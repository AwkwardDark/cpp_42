#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	protected:
			std::string	_type;

	public:
			WrongAnimal(void);
			WrongAnimal(std::string type);
			WrongAnimal(WrongAnimal const &src);
			virtual ~WrongAnimal(void);
			WrongAnimal &operator=(WrongAnimal const &src);
			virtual	void	makeSound(void) const;
			std::string		getType(void) const;		
};

#endif
