#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		Ice(Ice const &src);
		Ice &operator=(Ice const &src);
		AMateria *clone(void) const;
};

#endif
