/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:40:39 by juestrel          #+#    #+#             */
/*   Updated: 2024/11/04 19:04:46 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat firstOne("Paco", 5);
	Bureaucrat secondOne("Loli", 0);
	Bureaucrat thirdOne("Sisebuto", 154);
	Bureaucrat fourthOne;

	std::cout << firstOne << std::endl;
	std::cout << secondOne << std::endl;
	std::cout << thirdOne << std::endl;
	std::cout << fourthOne << std::endl;

	firstOne.incrementGrade();
	firstOne.decrementGrade();
	secondOne.incrementGrade();
	thirdOne.decrementGrade();
	return (0);
}