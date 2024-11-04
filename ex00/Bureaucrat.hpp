#ifndef BUREAUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	/* data */
public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &toCopy);
	Bureaucrat &operator=(const Bureaucrat &toCopy);
	~Bureaucrat(void);
};
#endif