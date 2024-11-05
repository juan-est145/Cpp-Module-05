#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &toCopy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &toCopy);
	void execute(Bureaucrat const &executor) const;
	~ShrubberyCreationForm(void);
};
#endif