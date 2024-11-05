/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:40:39 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/05 13:26:13 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form firstOne("Demolition form", 5, 5);
	Form secondOne("Labor Form", 2, 0);
	Form thirdOne("Other labor Form", 0, 2);
	Form fourthOne("Bar Form", 200, 150);
	Form fifthOne("Other bar Form", 150, 200);

	std::cout << firstOne << std::endl;
	std::cout << secondOne << std::endl;
	std::cout << thirdOne << std::endl;
	std::cout << fourthOne << std::endl;
	std::cout << fifthOne << std::endl;

	Bureaucrat highBureaucrat("Jeff", 1);
	Bureaucrat lowBureaucrat("Manny", 150);

	highBureaucrat.signForm(secondOne);
	lowBureaucrat.signForm(thirdOne);
	return (0);
}