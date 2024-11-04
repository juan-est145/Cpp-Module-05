#ifndef BUREAUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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