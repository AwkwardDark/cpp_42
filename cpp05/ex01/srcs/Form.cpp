#include "Form.hpp"

// Orthodox canonical form

Form::Form(void) : _name("unknown") , _signed(false) , _signGrade(150) , _execGrade(150)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string const name, int const signGrade, int const execGrade) : 
_name(name) , _signed(false) , _signGrade(signGrade) , _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form const &src) : 
_name(src._name) , _signGrade(src._signGrade) , _execGrade(src._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(Form const &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

// Getters and method beSigned

std::string const	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat const &bur)
{
	if (bur.getGrade() < this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

// Exceptions

const char * Form::GradeTooHighException::what() const throw()
{
	return ("form grade is too High");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("form grade is too Low");
}

// Insertion overload
std::ostream &operator<<(std::ostream &stream, Form const &form)
{
	stream << "Form name: " << form.getName() 
	<< ", signature grade: " << form.getSignGrade() 
	<< ", execution grade: " << form.getExecGrade() 
	<< ", is signed: " << form.getSigned() << ".";
	return (stream);
}
