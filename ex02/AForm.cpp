/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:24:34 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/05 11:59:11 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _target("Blank form"), _signGrade(150), _executeGrade(150), _isSigned(false) {}

AForm::AForm(const std::string target, unsigned int signGrade, unsigned int executeGrade)
	: _target(target), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	try
	{
		if (executeGrade < 1 || signGrade < 1)
			throw AForm::GradeTooHighException();
		if (executeGrade > 150 || signGrade > 150)
			throw AForm::GradeTooLowException();
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
		this->_executeGrade < 1 ? const_cast<unsigned int&>(this->_executeGrade) = 1 : this->_executeGrade;
		this->_signGrade < 1 ? const_cast<unsigned int&>(this->_signGrade) = 1 : this->_signGrade;
		std::cout << "Form " << this->_target << " has had it's grades corrected to the highest possible value" << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
		this->_executeGrade > 150 ? const_cast<unsigned int &>(this->_executeGrade) = 150 : this->_executeGrade;
		this->_signGrade > 150 ? const_cast<unsigned int &>(this->_signGrade) = 150 : this->_signGrade;
		std::cout << "Form " << this->_target << " has had it's grades corrected to the lowest possible value" << std::endl;
	}
}

AForm::AForm(const AForm &toCopy) : _target(toCopy._target), _signGrade(toCopy._signGrade), _executeGrade(toCopy._executeGrade)
{
	*this = toCopy;
}
AForm &AForm::operator=(const AForm &toCopy)
{
	if (this != &toCopy)
		this->_isSigned = toCopy._isSigned;
	return (*this);
}

std::string AForm::getTarget(void) const
{
	return (this->_target);
}

bool AForm::isSigned(void) const
{
	return (this->_isSigned);
}

unsigned int AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

unsigned int AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void AForm::beSigned(const Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::checkExecGrade(const Bureaucrat &Bureaucrat) const 
{
	if (!this->_isSigned)
		throw AForm::FormIsNotSignedException();
	if (Bureaucrat.getGrade() > this->_executeGrade)
		throw Bureaucrat::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const 
{
	this->checkExecGrade(executor);
	std::cout << "This form has been executed" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Destructor has been called" << std::endl;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form grade is too high, maximum is 1");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form grade is too low, minimum is 150");
}

const char *AForm::FormIsNotSignedException::what(void) const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &Form)
{
	out << "Form " << Form.getTarget() << " has a sign grade of " << Form.getSignGrade() << " and a execute grade of " << Form.getExecuteGrade();
	return (out);
}