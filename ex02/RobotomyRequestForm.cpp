/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:21:02 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/07 10:20:31 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Deafault", 75, 45)
{
	std::cout << "Robotomy form has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 75, 45)
{
	std::cout << "Robotomy form has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) : AForm(toCopy)
{
	std::cout << "Robotomy copy constructor has been used" << std::endl;
	*this = toCopy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &toCopy)
{
	if (this != &toCopy)
		AForm::operator=(toCopy);
	std::cout << "Copy assignment operator for Robotomy has been called" << std::endl;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkValidity(executor);
	std::cout << "*Drilling noises*. ";
	srand(time(NULL));
	rand() % 2 == 0 ? std::cout << "\033[1;32m" << this->getTarget() << " has been succesfully robotomized\033[0m" << std::endl : std::cout << "\033[1;31m" << this->getTarget() << " couldn't be robotomized\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Robotomy destructor has been called" << std::endl;
}