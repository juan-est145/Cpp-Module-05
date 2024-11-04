#ifndef BUREAUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	const std::string _name;
	unsigned int _grade;
public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &toCopy);
	Bureaucrat &operator=(const Bureaucrat &toCopy);
	~Bureaucrat(void);

	class GradeTooHighException : std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too high, the maximum is 1");
			}
	};
};
#endif