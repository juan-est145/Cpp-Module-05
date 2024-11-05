#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
private:
	typedef AForm *(Intern::*FormCreator)(const std::string &) const;
	AForm *createShrubberyForm(const std::string &target) const;
	AForm *createRobotomyForm(const std::string &target) const;
	AForm *createPresidentialPardonForm(const std::string &tasrget) const;

public:
	Intern(void);
	Intern(Intern &toCopy);
	Intern &operator=(Intern &toCopy);
	AForm *makeForm(const std::string &form, const std::string &target) const;
	~Intern(void);
};
#endif