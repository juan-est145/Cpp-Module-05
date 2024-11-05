#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &toCopy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &toCopy);
	void execute(Bureaucrat const &executor) const;
	virtual ~RobotomyRequestForm(void);
};

#endif