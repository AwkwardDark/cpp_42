#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	protected:
			std::string	_type;

	public:
			Animal(void);
			Animal(std::string type);
			Animal(Animal const &src);
			virtual ~Animal(void);
			Animal &operator=(Animal const &src);
			virtual	void	makeSound(void) const;
			std::string		getType(void) const;
};

#endif
