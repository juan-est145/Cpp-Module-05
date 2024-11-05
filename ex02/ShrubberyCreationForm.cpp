/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:54:03 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/05 14:49:55 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Deafault", 145, 137)
{
	std::cout << "Shrubbery form has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	std::cout << "Shrubbery form has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : AForm(toCopy)
{
	std::cout << "Shrubbery copy constructor has been used" << std::endl;
	*this = toCopy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &toCopy)
{
	if (this != &toCopy)
		AForm::operator=(toCopy);
	std::cout << "Copy assignment operator for Shrubbery form has been called" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->checkValidity(executor);
	std::ofstream targetFile;
	targetFile.open(this->getTarget().c_str());
	if (!targetFile.is_open())
	{
		std::cerr << "Failed to open " << this->getTarget() << " file" << std::endl;
		return;
	}
	targetFile << "     ccee88oo\n";
	targetFile << "  C8O8O8Q8PoOb o8oo\n";
	targetFile << " dOB69QO8PdUOpugoO9bD\n";
	targetFile << "CgggbU8OU qOp qOdoUOdcb\n";
	targetFile << "    6OuU  /p u gcoUodpP\n";
	targetFile << "      \\\\\\//  /douUP\n";
	targetFile << "        \\\\\\////\n";
	targetFile << "         |||/\\\n";
	targetFile << "        |||\\/\n";
	targetFile << "         |||||\n";
	targetFile << "   .....//||||\\....\n";
	targetFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Shrubbery destructor has been called" << std::endl;
}