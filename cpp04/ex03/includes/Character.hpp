#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		AMateria	*slots[4];
		std::string	_name;
		
	public:
		Character(void);
		Character(std::string name);
		virtual ~Character(void);
		Character(Character const &src);
		Character &operator=(Character const &src);
		std::string const &getName(void) const;
		void equip(AMateria *mat);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif
