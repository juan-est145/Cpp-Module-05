/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:31:53 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/05 14:49:51 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default", 25, 5)
{
	std::cout << "Presidential pardon form has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	std::cout << "Presidential pardon form has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) : AForm(toCopy)
{
	std::cout << "Presidential pardon copy constructor has been used" << std::endl;
	*this = toCopy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &toCopy)
{
	if (this != &toCopy)
		AForm::operator=(toCopy);
	std::cout << "Copy assignment operator for Presidential Pardon has been called" << std::endl;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkValidity(executor);
	std::cout << this->getTarget() << " has been pardoned by  Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Presidential Pardon destructor has been called" << std::endl;
}