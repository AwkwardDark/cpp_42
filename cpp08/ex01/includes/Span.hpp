#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class	Span
{
	private:
		unsigned int		_N;
		std::vector<int>	tab;
	
	public:
		// Canonical orthodox form
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span(Span const &src);
		Span &operator=(Span const &src);

		// Member functions
		void		addNumber(int value);
		int			shortestSpan(void);
		int			longestSpan(void);
		void		fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		std::vector<int> const	&get_tab(void) const;

		//Exceptions
		class	FullSpanException : public std::exception
		{
			const char * what() const throw();
		};

		class	SmallSpanException : public std::exception
		{
			const char * what() const throw();
		};
};

#endif
