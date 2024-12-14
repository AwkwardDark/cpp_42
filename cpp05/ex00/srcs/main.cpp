#include "Bureaucrat.hpp"

void	basic_test(void)
{
	Bureaucrat Jimmy("Jimmy", 7);

	std::cout << Jimmy << std::endl;
	Jimmy.upGrade();
	Jimmy.upGrade();
	Jimmy.upGrade();
	Jimmy.upGrade();
	std::cout << Jimmy << std::endl;
}

void	tooLow_test(void)
{
	Bureaucrat Jimmy("Jimmy", 151);
}

void	tooHigh_test(void)
{
	Bureaucrat Jimmy("Jimmy", 0);
}

void	downGrade_test(void)
{
	Bureaucrat Jimmy("Jimmy", 150);

	std::cout << Jimmy << std::endl;
	Jimmy.downGrade();
	std::cout << Jimmy << std::endl;
}

void	upGrade_test(void)
{
	Bureaucrat Jimmy("Jimmy", 1);

	std::cout << Jimmy << std::endl;
	Jimmy.upGrade();
	std::cout << Jimmy << std::endl;
}

int	main(void)
{
	// Standart test without exception
	try
	{
		basic_test();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
	std::cout << std::string(30, '-') << std::endl;
	
	// Test with exception when grade > 150
	try
	{
		tooLow_test();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
	std::cout << std::string(30, '-') << std::endl;
	
	// Test with exception when grade < 1
	try
	{
		tooHigh_test();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
	std::cout << std::string(30, '-') << std::endl;


	// Test when exception reached while downgrading
	try
	{
		downGrade_test();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
	std::cout << std::string(30, '-') << std::endl;

	// Test when exception reached while upgrading
	try
	{
		upGrade_test();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << END << std::endl;
	}
	return (0);
}
