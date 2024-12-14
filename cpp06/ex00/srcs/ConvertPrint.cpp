#include "ScalarConverter.hpp"

// Char
void convert_print_char(std::string str)
{
	char c;

	c = str.at(0);
	std::cout << "char:  '" << c << "'" << std::endl;
	std::cout << "int:    " << static_cast<int>(c) << std::endl;
	std::cout << "float:  " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

// Int, Float and Double
void convert_print_number(std::string str, int i, float f, double d, int precision)
{
	long double nb;
	int int_ovrflw = 0;
	int float_ovrflw = 0;
	int double_ovrflw = 0;

	nb = strtold(str.c_str(), NULL); // Transform to long double to check all type overflows

	// Char print
	if (nb >= 0 && nb <= 127)
	{
		if (isprint(nb))
			std::cout << "char:  '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "char:   Non displayable" << std::endl;
	}
	else
		std::cout << "char:   impossible" << std::endl;

	// Checking type overflows
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
	{
		std::cout << "int:    impossible, overflow" << std::endl;
		int_ovrflw = 1;
	}
	if (nb < -std::numeric_limits<float>::max() || nb > std::numeric_limits<float>::max())
	{
		std::cout << "float:  impossible, overflow" << std::endl;
		float_ovrflw = 1;
	}
	if (nb < -std::numeric_limits<double>::max() || nb > std::numeric_limits<double>::max())
	{
		std::cout << "double: impossible, overflow" << std::endl;
		double_ovrflw = 1;
	}

	// Int print
	if (!int_ovrflw)
		std::cout << "int:    " << i << std::endl;

	// Double and float print
	if (!precision)
	{
		if (!float_ovrflw)
			std::cout << "float:  " << f << ".0f" << std::endl;
		if (!double_ovrflw)
			std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		if (!float_ovrflw)
		{
			std::cout << std::setprecision(precision) << std::fixed;
			std::cout << "float:  " << f << "f" << std::endl;
		}
		if (!double_ovrflw)
		{
			std::cout << std::setprecision(precision) << std::fixed;
			std::cout << "double: " << d << std::endl;
		}
	}
}

// Special
void convert_print_special(std::string str)
{
	std::cout << "char:   impossible" << std::endl;
	std::cout << "int:    impossible" << std::endl;
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
	{
		std::cout << "float:  " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
	else
	{
		std::cout << "float:  " << str << std::endl;
		std::cout << "double: " << str.erase(str.find('f'), 1) << std::endl;
	}
}
