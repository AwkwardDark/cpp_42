#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *material[4];

	public:
		MateriaSource(void);
		virtual ~MateriaSource(void);
		void learnMateria(AMateria *mat);
		AMateria *createMateria(std::string const &type);
};

#endif
