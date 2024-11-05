#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string _target;
	const unsigned int _signGrade;
	const unsigned int _executeGrade;
	bool _isSigned;

public:
	AForm(void);
	AForm(const std::string target, unsigned int signGrade, unsigned int executeGrade);
	AForm(const AForm &toCopy);
	AForm &operator=(const AForm &toCopy);
	std::string getTarget(void) const;
	bool isSigned(void) const;
	unsigned int getSignGrade(void) const;
	unsigned int getExecuteGrade(void) const;
	void beSigned(const Bureaucrat &Bureaucrat);
	void checkExecGrade(const Bureaucrat &Bureaucrat) const;
	virtual void execute(Bureaucrat const &executor) const = 0;
	~AForm(void);

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
	class FormIsNotSignedException : std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
};
std::ostream &operator<<(std::ostream &out, const AForm &Form);

#endif