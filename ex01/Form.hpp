#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const unsigned int _signGrade;
	const unsigned int _executeGrade;
	bool _isSigned;

public:
	Form(void);
	Form(const std::string name, unsigned int signGrade, unsigned int executeGrade);
	Form(const Form &toCopy);
	Form &operator=(const Form &toCopy);
	std::string getName(void) const;
	bool isSigned(void) const;
	unsigned int getSignGrade(void) const;
	unsigned int getExecuteGrade(void) const;
	void beSigned(const Bureaucrat &Bureaucrat);
	~Form(void);

	class GradeTooHighException : std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class GradeTooLowException : std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
};
std::ostream &operator<<(std::ostream &out, const Form &Form);

#endif