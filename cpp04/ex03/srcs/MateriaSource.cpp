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
	delete[] this->material;
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
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->material[i] && this->material[i]->getType().compare(type))
			return (this->material[i].clone());
	}
	std::cout << "Type  is unknow" << std::endl;
	return (0);
}
