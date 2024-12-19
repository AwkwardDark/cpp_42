#include "RPN.hpp"

// Canonical Orthodox Form

RPN::RPN(void)
{
	try
	{
		parse_calculate("1 1 +");
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

RPN::RPN(std::string operation) : _operation(operation)
{
	try
	{
		parse_calculate(_operation);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

RPN::~RPN(void)
{
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN &RPN::operator=(RPN const &src)
{
	if (this != &src)
	{
		this->_operation = src._operation;
		this->_rpnStack = src._rpnStack;
	}
	return (*this);
}

// Methods

void	RPN::parse_calculate(std::string str)
{
	std::string token;
	std::size_t	sep;
	int			last = 0;
	
	if (!str.compare(""))
		throw std::runtime_error("Input operations is empty.");
	for (std::size_t i = 0; i < str.length(); i++)
	{
		sep = str.find_first_of(' ', last);
		if (sep == std::string::npos)
		{
			token = str.substr(last);
			if (!is_number(token) && !is_operator(token))
				throw std::runtime_error("Error: bad operators or numbers.");
			rpn(token);
			break ;
		}
		else
			token = str.substr(last, sep - last);
		if (!is_number(token) && !is_operator(token))
			throw std::runtime_error("Error: bad operators or numbers.");
		last = sep + 1;
		rpn(token);
	}
	std::cout << _rpnStack.top() << std::endl;
}

void	RPN::rpn(std::string token)
{
	std::stringstream	n1s;
	std::stringstream	n2s;
	std::stringstream	ress;
	int					n1;
	int					n2;
	int					res = 0;
	
	if (_rpnStack.size() == 0 && is_operator(token))
		throw std::runtime_error("Error: syntax is not corect.");
	if (is_operator(token))
	{
		n1s << _rpnStack.top();
		_rpnStack.pop();
		if (_rpnStack.size() == 0)
			throw std::runtime_error("Error: syntax is not corect.");
		n2s << _rpnStack.top();
		_rpnStack.pop();
		n1s >> n1;
		n2s >> n2;
		if (!token.compare("+"))
			res = n2 + n1;
		else if (!token.compare("-"))
			res = n2 - n1;
		else if (!token.compare("*"))
			res = n2 * n1;
		else if (!token.compare("/"))
			res = n2 / n1;
		ress << res;
		_rpnStack.push(ress.str());
		return ;
	}
	_rpnStack.push(token);
}

bool	RPN::is_number(std::string str)
{
	std::stringstream	sstr;
	int					nb;

	if (!str.compare(""))
		return (false);
	for(std::size_t i = 0; i < str.length(); i++)
	{
		if (str.at(i) < '0' || str.at(i) > '9')
			return (false);
	}
	sstr << str;
	sstr >> nb;
	if (nb >= 10)
		throw std::runtime_error("Numbers must be lower than 10.");
	else if (nb < 0)
		throw std::runtime_error("Numbers must be positive.");
	return (true);
}

bool	RPN::is_operator(std::string str)
{
	if (!str.compare("+") || !str.compare("-") || !str.compare("*") || !str.compare("/"))
		return (true);
	return (false);
}
