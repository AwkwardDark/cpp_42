#include "Form.hpp"

void	toLow_test(void)
{
	Form form("contract", 151, 30);
}

void	toHigh_test(void)
{
	Form form("contract", 2, 0);
}

void	signSucces_test(void)
{
	Bureaucrat Jimmy("Jimmy", 20);
	Form		form("contract", 30, 25);

	Jimmy.signForm(form);
	Jimmy.signForm(form);
}

void	signFail_test(void)
{
	Bureaucrat Jimmy("Jimmy", 20);
	Form		form("contract", 10, 5);

	Jimmy.signForm(form);
}

int	main(void)
{
	// Test with exception when form grade > 150
	try
	{
		toLow_test();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
	std::cout << std::string(30, '-') << std::endl;
	
	// Test with exception when  form grade < 1
	try
	{
		toHigh_test();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
	std::cout << std::string(30, '-') << std::endl;


	// Test when bureaucrat grade is higher than form grade(success)
	try
	{
		signSucces_test();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
	std::cout << std::string(30, '-') << std::endl;

	// Test when bureaucrat grade is lower than form grade(fail)
	try
	{
		signFail_test();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}

	return (0);
}
