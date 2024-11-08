/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:24:34 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/05 14:50:00 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Blank form"), _signGrade(150), _executeGrade(150)
{
	this->_isSigned = false;
	std::cout << "Form " << this->_name << " has been created" << std::endl;
}

Form::Form(const std::string name, unsigned int signGrade, unsigned int executeGrade)
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	try
	{
		if (executeGrade < 1 || signGrade < 1)
			throw Form::GradeTooHighException();
		if (executeGrade > 150 || signGrade > 150)
			throw Form::GradeTooLowException();
		std::cout << "Form " << this->_name << " has been created" << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
		this->_executeGrade < 1 ? const_cast<unsigned int &>(this->_executeGrade) = 1 : this->_executeGrade;
		this->_signGrade < 1 ? const_cast<unsigned int &>(this->_signGrade) = 1 : this->_signGrade;
		std::cout << "Form " << this->_name << " has had it's grades corrected to the highest possible value" << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
		this->_executeGrade > 150 ? const_cast<unsigned int &>(this->_executeGrade) = 150 : this->_executeGrade;
		this->_signGrade > 150 ? const_cast<unsigned int &>(this->_signGrade) = 150 : this->_signGrade;
		std::cout << "Form " << this->_name << " has had it's grades corrected to the lowest possible value" << std::endl;
	}
}

Form::Form(const Form &toCopy) : _name(toCopy._name), _signGrade(toCopy._signGrade), _executeGrade(toCopy._executeGrade)
{
	std::cout << "Form copy constructor was called" << std::endl;
	*this = toCopy;
}
Form &Form::operator=(const Form &toCopy)
{
	std::cout << "Form copy assignment operator was called" << std::endl;
	if (this != &toCopy)
		this->_isSigned = toCopy._isSigned;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::isSigned(void) const
{
	return (this->_isSigned);
}

unsigned int Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

unsigned int Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void Form::beSigned(const Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

Form::~Form(void)
{
	std::cout << "Destructor has been called" << std::endl;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade is too high, maximum is 1");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade is too low, minimum is 150");
}

std::ostream &operator<<(std::ostream &out, const Form &Form)
{
	out << "Form " << Form.getName() << " has a sign grade of " << Form.getSignGrade() << " and a execute grade of " << Form.getExecuteGrade();
	return (out);
}