#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScavalarConverter constructor called" << std::endl;
}
ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScavalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "ScavalarConverter copy constructor called" << std::endl;
	(void)src;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return (*this);
}

// Convert method
void	ScalarConverter::convert(std::string str)
{
	int	prec;
	
	if (str.length() == 0)
	{
		std::cout << "Error, input can't be empty" << std::endl;
		return ;
	}
	if (is_char(str))
		convert_print_char(str);
	else if (is_number(str))
	{
		prec = calculate_precision(str);
		if (str.find('.') == str.npos && str.find('f') == str.npos) //if there isnt '.' and 'f' is an int
		{
			int	i = atoi(str.c_str());
			convert_print_number(str, i, static_cast<float>(i), static_cast<double>(i), prec);
		}
		else if (str.find('f') == str.npos) // if there's a '.' but not an 'f' is a double
		{
			float	f = strtof(str.c_str(), NULL);
			convert_print_number(str, static_cast<int>(f), f, static_cast<double>(f), prec);
		}
		else
		{
			double	d = strtod(str.c_str(), NULL);
			convert_print_number(str, static_cast<int>(d), static_cast<float>(d), d, prec);
		}
	}
	else if (is_special(str))
		convert_print_special(str);
	else
		std::cout << "Error, wrong input, try only with printable char, int, float or double types" << std::endl;
}
