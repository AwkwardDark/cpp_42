#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)src;
}

Intern &Intern::operator=(Intern const &src)
{
	(void)src;
	return (*this);
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target) const
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*func[3])(std::string target) =
		{&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form)
		{
			std::cout << GREEN << "Intern creates " << form << END << std::endl;
			return (func[i](target));
		}
	}
	std::cout << RED << "Form " << form << " doesn't exit, Intern can't create the form objet" << END << std::endl;
	return (NULL);
}
