#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <list>
# include <vector>

// Exception
class OcurrenceNotFound : public std::exception
{
	public:
		const char * what() const throw()
		{
			return ("Ocurrence of value not found on the container");
		}
};

// Searches for the first occurence of value in the container of type <T>
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value); // "find" algorith will do the job for us
	if (it != container.end())
		return (it);
	throw OcurrenceNotFound();
};

#endif
