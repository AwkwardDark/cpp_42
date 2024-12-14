#include "Span.hpp"

// Canonical Orthodox Form

Span::Span(void) : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::~Span(void) {}

Span::Span(Span const &src)
{
	*this = src;
}

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_N = src._N;
		this->tab = src.get_tab();
	}
	return (*this);
}

// Member functions

std::vector<int> const	&Span::get_tab(void) const
{
	return (this->tab);
}

void	Span::addNumber(int value)
{
	if (this->tab.size() >= this->_N)
		throw Span::FullSpanException();
	this->tab.push_back(value);
}

int		Span::shortestSpan(void)
{
	if (this->tab.size() < 2)
		throw	SmallSpanException();
	int	shortest = std::abs(this->tab.at(0) - this->tab.at(1));
	std::vector<int>::iterator it1 = this->tab.begin();
	for(it1; it1 != this->tab.end(); it1++)
	{
		std::vector<int>::iterator it2 = it1 + 1;
		for(it2; it2 != this->tab.end(); it2++)
		{
			if (shortest > std::abs(*it1 - *it2))
				shortest = std::abs(*it1 - *it2);
		}
	}
	return (shortest);
}

// Iterates to find max and min to output max - min
int		Span::longestSpan(void)
{
	if (this->tab.size() < 2)
		throw	SmallSpanException();
	// Searching the max
	int	max = this->tab.at(0);
	std::vector<int>::iterator itm = this->tab.begin() + 1;
	for(itm; itm != this->tab.end(); itm++)
	{
		if (*itm > max)
			max = *itm;
	}
	// Searching the min
	int	min = this->tab.at(0);
	std::vector<int>::iterator it = this->tab.begin() + 1;
	for(itm; itm != this->tab.end(); itm++)
	{
		if (*itm < min)
			min = *itm;
	}
	return (max - min);
}

void	Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int len = std::distance(begin, end);
	if (len > this->_N)
		throw Span::SmallSpanException();
	this->tab.assign(begin, end);
}

// Exceptions

const char * Span::FullSpanException::what() const throw()
{
	return ("Failed to add the element, span container is full ");
}

const char * Span::SmallSpanException::what() const throw()
{
	return ("There aren't enough numbers to find a Span");
}
