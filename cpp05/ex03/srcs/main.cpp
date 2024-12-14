#include "Intern.hpp"

void	Intern_succes1(void)
{
	Intern	scfIntern;
	AForm *SCF;
	
	SCF  = scfIntern.makeForm("shrubbery creation", "tree");
	Bureaucrat Jimmy("Jimmy", 137);

	Jimmy.signForm(*SCF);
	Jimmy.executeForm(*SCF);
	delete SCF;
}

void	Intern_succes2(void)
{
	Intern	scfIntern;
	AForm *RRF;
	
	RRF  = scfIntern.makeForm("robotomy request", "robot");
	Bureaucrat Jimmy("Jimmy", 44);

	Jimmy.signForm(*RRF);
	Jimmy.executeForm(*RRF);
	delete RRF;
}

void	Intern_succes3(void)
{
	Intern	scfIntern;
	AForm *PPF;
	
	PPF  = scfIntern.makeForm("presidential pardon", "pardon");
	Bureaucrat Jimmy("Jimmy", 5);

	Jimmy.signForm(*PPF);
	Jimmy.executeForm(*PPF);
	delete PPF;
}

void	Intern_fail(void)
{
	Intern	failIntern;
	AForm *fail;
	
	fail  = failIntern.makeForm("extrange alien", "ship");
}

int	main(void)
{
	// Bureaucrat grade lower than signature shrubbery's grade
	Intern_succes1();
	std::cout << std::string(40, '*') << std::endl << std::string(40, '*') << std::endl;

	// Bureaucrat grade lower than signature robotomy's grade
	Intern_succes2();
	std::cout << std::string(40, '*') << std::endl << std::string(40, '*') << std::endl;

	// Bureaucrat grade lower than signature presidential's grade
	Intern_succes3();
	std::cout << std::string(40, '*') << std::endl << std::string(40, '*') << std::endl;

	//Form target doesn't exist
	Intern_fail();

	return (0);
}
