#include "ScalarConverter.hpp"

bool is_char(std::string str)
{
	if (str.length() == 1 && !isdigit(str.at(0)) && isprint(str.at(0)))
		return (true);
	return (false);
}

bool is_number(std::string str)
{
	size_t i = 0;
	bool digit = false;
	bool dot = false;

	if (str.at(0) == '-')
		i++;
	while (i < str.length())
	{
		if (isdigit(str.at(i)))
			digit = true;
		else if ((str.find('.') == 0) || (str.find('.') == str.length() - 1))
			return (false);
		else if ((str.at(i) == '.') && (str.find('f') != i + 1) && (dot == false) && (digit == true))
			dot = true;
		else if ((str.at(i) == 'f') && (str.find('f') == str.length() - 1) && (digit == true) && (dot == true))
			return (true);
		else
			return (false);
		i++;
	}
	return (true);
}

bool is_special(std::string str)
{
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf") || !str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return (true);
	return (false);
}

int calculate_precision(std::string str)
{
	int p = 0;

	if (str.find('.') == str.npos)
		return (p);
	else
	{
		size_t i = str.find('.') + 1;
		while (i < str.find('f') && str.c_str()[i] != '\0')
		{
			p++;
			i++;
		}
	}
	return (p);
}
