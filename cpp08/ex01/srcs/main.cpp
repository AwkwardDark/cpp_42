#include "Span.hpp"

int	main(void)
{
	srand(time(0));
	// Creating a container to have the begin and end iterator
	std::vector<int>	vec;
	for(int i = 0; i < 10000; i++)
		vec.push_back(rand());
	
	// Initializing the Span
	Span	spanVec(10000);
	spanVec.fillSpan(vec.begin(), vec.end()); //Filling the span with the iterator range

	std::cout << "Longest span:  " << spanVec.longestSpan() << std::endl;
	std::cout << "Shortest span: " << spanVec.shortestSpan() << std::endl << std::endl;
	
	// Adding a number when the Span is full
	try
	{
		spanVec.addNumber(5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Adding a number when the Span is full
	try
	{
		spanVec.fillSpan(vec.begin(), vec.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Span small(1);

	// Trying to calculate the shortestspan when is not big enough
	try
	{
		small.addNumber(5);
		small.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}

// Subject main

// int	main(void)
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return (0);
// }
