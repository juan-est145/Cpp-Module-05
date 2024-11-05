/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:38:53 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/05 14:50:11 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	std::cout << "An intern has been hired" << std::endl;
}

Intern::Intern(Intern &toCopy)
{
	*this = toCopy;
	std::cout << "An intern has been hired" << std::endl;
}

Intern &Intern::operator=(Intern &toCopy)
{
	(void)toCopy;
	std::cout << "An intern has been hired" << std::endl;
	return (*this);
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) const
{
	std::string forms[3] = {"shrubbery", "robotomy", "presidentialPardon"};
	FormCreator formCreator[3] = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialPardonForm};
	for (size_t i = 0; i < sizeof(forms) / sizeof(forms[0]); i++)
	{
		if (form == forms[i])
			return (this->*formCreator[i])(target);
	}
	return (NULL);
}

AForm *Intern::createShrubberyForm(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

Intern::~Intern(void)
{
	std::cout << "An intern has been fired" << std::endl;
}