/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:40:39 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/05 12:22:46 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat highOne("Jimena", 1);
	Bureaucrat lowOne("Paco", 72);
	RobotomyRequestForm *robotomy = new RobotomyRequestForm("Someone");
	RobotomyRequestForm *lowExec = new RobotomyRequestForm("lowExec");

	highOne.executeForm(*robotomy);
	highOne.signForm(*robotomy);
	highOne.executeForm(*robotomy);
	lowOne.signForm(*lowExec);
	lowOne.executeForm(*lowExec);
	highOne.executeForm(*lowExec);
	delete robotomy;
	delete lowExec;
	return (0);
}