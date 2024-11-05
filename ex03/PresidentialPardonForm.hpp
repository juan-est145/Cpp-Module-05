#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &toCopy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &toCopy);
	void execute(Bureaucrat const &executor) const;
	~PresidentialPardonForm(void);
};

#endif