#include "Bureaucrat.hpp"

// Orthodox Canonical Form

Bureaucrat::Bureaucrat(void) : _name("unknown") , _grade(150)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade > 150)
		throw(GradeTooLowException());
	else if (grade < 1)
		throw(GradeTooHighException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

// Member functions (getters and grade change)

std::string const	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::upGrade(void)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::downGrade(void)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

// Insertion overload

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &src)
{
	stream << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (stream);
}

// Exceptions

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error, grade is too High");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error, grade is too Low");
}
