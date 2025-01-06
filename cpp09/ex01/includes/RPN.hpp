#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <stdbool.h>
# include <sstream>
# include <exception>

# define RED     "\033[31m"
# define RESET   "\033[0m"

class RPN
{
	private:
		std::string	_operation;
		std::stack<std::string>	_rpnStack;
	public:
		// Canonical Orthodox Form
		RPN(void);
		RPN(std::string operation);
		~RPN(void);
		RPN(RPN const &src);
		RPN &operator=(RPN const &src);
		// Methods
		void	parse_calculate(std::string str);
		void	rpn(std::string token);
		bool	is_number(std::string str);
		bool	is_operator(std::string str);

};

#endif
