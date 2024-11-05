#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	unsigned int _grade;

public:
	Bureaucrat(void);
	Bureaucrat(const std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &toCopy);
	Bureaucrat &operator=(const Bureaucrat &toCopy);
	std::string getName() const;
	unsigned int getGrade() const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm &Form);
	void executeForm(AForm const &form) const;
	~Bureaucrat(void);

	class GradeTooHighException : std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);

#endif