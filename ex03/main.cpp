/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:40:39 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/05 14:50:20 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	Bureaucrat highOne("Jimena", 1);
	Bureaucrat lowOne("Paco", 72);
	AForm *robotomy = intern.makeForm("robotomy", "Someone");
	AForm *lowExec = intern.makeForm("robotomy", "lowExec");
	AForm *pardon = intern.makeForm("presidentialPardon", "Arthur");
	AForm *shrubbery = intern.makeForm("shrubbery", "Arbol");

	std::cout << "\n";

	{
		highOne.executeForm(*robotomy);
		highOne.signForm(*robotomy);
		highOne.executeForm(*robotomy);
		lowOne.signForm(*lowExec);
		lowOne.executeForm(*lowExec);
		highOne.executeForm(*lowExec);
	}

	{
		lowOne.signForm(*pardon);
		highOne.signForm(*pardon);
		lowOne.signForm(*pardon);
		lowOne.executeForm(*pardon);
		highOne.executeForm(*pardon);
	}

	{
		lowOne.signForm(*shrubbery);
		lowOne.executeForm(*shrubbery);
		highOne.signForm(*shrubbery);
		highOne.executeForm(*shrubbery);
	}

	std::cout << "\n";
	delete robotomy;
	delete lowExec;
	delete pardon;
	delete shrubbery;
	return (0);
}