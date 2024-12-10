#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"
class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(std::string const &type);
		~AMateria(void);
		AMateria(AMateria const &src);
		AMateria &operator=(AMateria const &src);
		std::string const & getType(void) const; //Returns the materia type
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter &target);
};

#endif
