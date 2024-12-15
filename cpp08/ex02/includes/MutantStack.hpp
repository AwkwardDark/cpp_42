#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		// Canonical orthodox form
		MutantStack<T>(void) {}
		~MutantStack<T>(void) {}
		MutantStack<T>(MutantStack<T> const &src) { *this = src; }
		MutantStack<T> &operator=(MutantStack const &src)
		{
			if (this != &src)
				std::stack<T>::operator=(src);
			return (*this);
		}

		// Typedef for 4 kinds of iterators
		typedef typename	std::stack<T>::container_type				container_type;
		typedef typename	container_type::iterator					iterator;
		typedef typename	container_type::const_iterator				const_iterator;
		typedef typename	container_type::reverse_iterator			reverse_iterator;
		typedef typename	container_type::const_reverse_iterator		const_reverse_iterator;

		// Iterators .begin() and .end() definition
		iterator	begin(void) { return(this->c.begin()); }
		iterator	end(void) { return(this->c.end()); }

		const_iterator	begin(void) const { return (this->c.begin()); };
		const_iterator	end(void) const { return(this->c.end()); };

		reverse_iterator	rbegin(void) { return(this->c.rbegin()); }
		reverse_iterator	rend(void) { return(this->c.rend()); }

		const_reverse_iterator	rbegin(void) const { return(this->c.rbegin()); }
		const_reverse_iterator	rend(void) const { return(this->c.rend()); }
};

#endif
