#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <cstdlib>

template <typename T>
class	Array
{
	private:
		unsigned int	_size;
		T				*tab;
	public:
		// Default constructor
		Array<T>(void) : _size(0) , tab(NULL) {}
		
		// Constructor whith parameter
		Array<T>(unsigned int n) : _size(n) , tab(new T[n]) {}
		
		// Default destructor
		~Array(void) { delete[] this->tab; }
		
		// Copy constructor
		Array<T>(Array<T> const &src)
		{
			this->_size = src.size();
			this->tab = new T[src.size()];
			for (unsigned int i = 0; i < this->_size; i++)
				this->tab[i] = src.tab[i];
		}

		// Asignation overload
		Array<T> &operator=(Array<T> const &src)
		{
			if (this != &src)
			{
				if (this->_size)
					delete[] this->tab;
				this->_size = src.size();
				this->tab = new T[src.size()];
				for (unsigned int i = 0; i < this->_size; i++)
					this->tab[i] = src.tab[i];
			}
			return (*this);
		}
		
		// Subscript overload (Accessor)
		T &operator[](const int n) const
		{
			unsigned int	i = static_cast<unsigned int>(n);
			
			if (i < 0 || i >= this->_size)
				throw std::out_of_range("index it's out of bounds"); // Exception that already exists
			return (this->tab[i]);
		}

		// Size getter method
		unsigned int	size(void) const { return (this->_size); }
};

#endif
