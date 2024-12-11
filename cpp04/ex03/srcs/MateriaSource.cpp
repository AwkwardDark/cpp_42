#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->material[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->material[i];
}

void MateriaSource::learnMateria(AMateria *mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->material[i])
		{
			this->material[i] = mat;
			return;
		}
	}
	std::cout << "You have a full inventory, you can't learn more Materia" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->material[i] && this->material[i]->getType().compare(type))
			return (this->material[i]->clone());
	}
	std::cout << "Type is unknow" << std::endl;
	return (0);
}
