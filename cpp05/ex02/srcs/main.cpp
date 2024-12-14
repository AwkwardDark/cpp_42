#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	Shrubbery_fail(void)
{
	AForm *SCF = new ShrubberyCreationForm("contract");
	Bureaucrat Jimmy("Jimmy", 146);

	Jimmy.signForm(*SCF);
	Jimmy.executeForm(*SCF);
	delete SCF;
}

void	Shrubbery_succes(void)
{
	AForm *SCF = new ShrubberyCreationForm("contract");
	Bureaucrat Jimmy("Jimmy", 136);

	Jimmy.signForm(*SCF);
	Jimmy.executeForm(*SCF);
	delete SCF;
}

void	Robotomy_fail(void)
{
	AForm *RRF = new RobotomyRequestForm("contract");
	Bureaucrat Jimmy("Jimmy", 79);

	Jimmy.signForm(*RRF);
	Jimmy.executeForm(*RRF);
	delete RRF;
}

void	Robotomy_succes(void)
{
	AForm *RRF = new RobotomyRequestForm("contract");
	Bureaucrat Jimmy("Jimmy", 44);

	Jimmy.signForm(*RRF);
	Jimmy.executeForm(*RRF);
	delete RRF;
}

void	Presidential_fail(void)
{
	AForm *PPF = new PresidentialPardonForm("contract");
	Bureaucrat Jimmy("Jimmy", 26);

	Jimmy.signForm(*PPF);
	Jimmy.executeForm(*PPF);
	delete PPF;
}

void	Presidential_succes(void)
{
	AForm *PPF = new PresidentialPardonForm("contract");
	Bureaucrat Jimmy("Jimmy", 5);

	Jimmy.signForm(*PPF);
	Jimmy.executeForm(*PPF);
	delete PPF;
}

int	main(void)
{
	// Bureaucrat grade lower than signature shrubbery's grade
	Shrubbery_fail();
	std::cout << std::string(40, '*') << std::endl << std::string(40, '*') << std::endl;

	// Bureaucrat grade higher than execution shrubbery's grade
	Shrubbery_succes();
	std::cout << std::string(40, '*') << std::endl << std::string(40, '*') << std::endl;
	
	// Bureaucrat grade lower than signature robotomy's grade
	Robotomy_fail();
	std::cout << std::string(40, '*') << std::endl << std::string(40, '*') << std::endl;

	// Bureaucrat grade higher than execution robotomy's grade
	Robotomy_succes();
	std::cout << std::string(40, '*') << std::endl << std::string(40, '*') << std::endl;

	// Bureaucrat grade lower than signature presidential's grade
	Presidential_fail();
	std::cout << std::string(40, '*') << std::endl << std::string(40, '*') << std::endl;

	// Bureaucrat grade higher than execution presidential's grade
	Presidential_succes();

	return (0);
}
