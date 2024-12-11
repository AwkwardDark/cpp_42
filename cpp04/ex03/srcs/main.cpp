#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

int main(void)
{
	// Initilize
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* mario = new Character("mario");
	std::cout << std::string(30, '-') << std::endl;	

	// Creating to materia
	AMateria* tmp1;
	tmp1 = src->createMateria("ice");
	mario->equip(tmp1);
	AMateria* tmp2;
	tmp2 = src->createMateria("cure");
	mario->equip(tmp2);
	std::cout << std::string(30, '-') << std::endl;	

	ICharacter* bob = new Character("bob");
	
	// Bad idx
	mario->use(-1, *bob);
	mario->use(4, *bob);
	std::cout << std::string(30, '-') << std::endl;	

	// Using materia
	mario->use(0, *bob);
	mario->use(1, *bob);
	mario->use(2, *bob);
	std::cout << std::string(30, '-') << std::endl;	

	//Unequip
	mario->unequip(0);
	mario->unequip(1);
	mario->unequip(2);
	std::cout << std::string(30, '-') << std::endl;	

	// Free
	delete bob;
	delete mario;
	delete src;
	delete tmp1;
	delete tmp2;
	
	return (0);
}
