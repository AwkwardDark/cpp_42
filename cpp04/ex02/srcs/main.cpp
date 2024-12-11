#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	// Initialize
	const Animal* tab[6];
	for (int i = 0; i < 3; i++)
			tab[i] = new Cat();
	for (int i = 3; i < 6; i++)
			tab[i] = new Dog();
	std::cout << std::string(30, '-') << std::endl;	

	// Display
	for (int i = 0; i < 6; i++)
		std::cout << "index: " << i << " -> " << tab[i]->getType() << std::endl;
	for (int i = 0; i < 6; i++)
		tab[i]->makeSound();
	std::cout << std::string(30, '-') << std::endl;	

	// Free
	for (int i = 0; i < 6; i++)
		delete tab[i];
	std::cout << std::string(30, '-') << std::endl;	

	// Deep copy check
	Cat cat;
	cat.setIdea("I want to sleep", 0);
	Cat cat2 = cat;
	std::cout << cat2.getIdea(0) << std::endl;
	cat2.setIdea("I want to eat", 0);
	std::cout << cat.getIdea(0) << std::endl;
	std::cout << cat2.getIdea(0) << std::endl;
	
	return (0);
}
