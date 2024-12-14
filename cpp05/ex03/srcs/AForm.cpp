#include "AForm.hpp"

// Orthodox canonical form

AForm::AForm(void) : _name("unknown") , _signed(false) , _signGrade(150) , _execGrade(150)
{
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(std::string const name, int const signGrade, int const execGrade) : 
_name(name) , _signed(false) , _signGrade(signGrade) , _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(AForm const &src) : 
_name(src._name) , _signGrade(src._signGrade) , _execGrade(src._execGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = src;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

// Getters and method beSigned

std::string const	AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

void	AForm::beSigned(Bureaucrat const &bur)
{
	if (bur.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}

// Exceptions

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("form grade is too High");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("form grade is too Low");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("form is not signed");
}

// Insertion overload
std::ostream &operator<<(std::ostream &stream, AForm const &form)
{
	stream << "Form name: " << form.getName() 
	<< ", signature grade: " << form.getSignGrade() 
	<< ", execution grade: " << form.getExecGrade() 
	<< ", is signed: " << form.getSigned() << ".";
	return (stream);
}
