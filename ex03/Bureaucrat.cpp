/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:57:15 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/05 14:50:09 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Billy")
{
	this->_grade = 150;
	std::cout << "Default bureaucrat constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade = grade;
		std::cout << "Bureaucrat " << this->_name << " has been brought to this miserable job with a grade of " << this->_grade << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		this->_grade = 150;
		std::cout << "Bureaucrat " << this->_name << " has been given a correct grade of " << this->_grade << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
		this->_grade = 1;
		std::cout << "Bureaucrat " << this->_name << " has been given a correct grade of " << this->_grade << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy)
{
	std::cout << "Copy constructor was called" << std::endl;
	*this = toCopy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &toCopy)
{
	std::cout << "Copy assignment operator was called" << std::endl;
	if (this != &toCopy)
		this->_grade = toCopy._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade--;
		std::cout << "Bureaucrat " << this->_name << " now has a grade of " << this->_grade << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "Bureaucrat " << this->_name << " already has the highest rank" << std::endl;
	}
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
		std::cout << "Bureaucrat " << this->_name << " now has a grade of " << this->_grade << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "Bureaucrat " << this->_name << " already has the lowest rank" << std::endl;
	}
}

void Bureaucrat::signForm(AForm &Form)
{
	try
	{
		if (Form.isSigned())
		{
			std::cout << "Form " << Form.getTarget() << " has already been signed" << std::endl;
			return;
		}
		Form.beSigned(*this);
		std::cout << "Bureaucrat " << this->getName() << " signed Form " << Form.getTarget() << std::endl;
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "Bureaucrat " << this->getName() << " does not have clearance to sign this form" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed form with target " << form.getTarget() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Can't execute form, " << e.what() << '\n';
	}
	catch (const AForm::FormIsNotSignedException &e)
	{
		std::cerr << "Can't execute form, " << e.what() << '\n';
	}
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor was called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << Bureaucrat.getName() << " is a bureaucrat with a grade of " << Bureaucrat.getGrade();
	return (out);
}