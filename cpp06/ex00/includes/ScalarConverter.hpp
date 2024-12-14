#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <stdlib.h>
# include <math.h>
# include <iomanip>
# include <stdbool.h>

class	ScalarConverter
{
	// Canonical Orthodox form on private to avoid the class to be instantiable
	private:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &src);
	public:
		static void	convert(std::string str);
};

bool	is_char(std::string str);
bool	is_number(std::string str);
bool	is_special(std::string str);
int		calculate_precision(std::string str);
void	convert_print_char(std::string str);
void	convert_print_number(std::string str, int i, float f, double d, int precision);
void	convert_print_special(std::string str);

#endif
