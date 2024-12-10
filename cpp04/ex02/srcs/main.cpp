#include "Cat.hpp"
#include "Dog.hpp"

std::ostream& operator<<(std::ostream& stream, const Animal &Animal)
{
	stream << "I am an animal of type " << Animal.getType();
	return (stream);
}

int	main(void)
{
	const Animal* Aj = new Dog();
	const Animal* Ai = new Cat(); 
	const int size = 10;
	Animal* Animalstab[size];

	// for (int i = 0; i < size; i++)
	// {
	// 	Aanimalstab[i] = NULL;
	// }
	// for (int i = 0; i < size; i++)
	// {
	// 	if (Aanimalstab[i] == NULL)
	// 		std::cout << "NULL" << std::endl;
	// }

	for (int i = 0; i < size / 2; i++)
		Animalstab[i] = new Cat();

	for (int i = size / 2; i < size; i++)
		Animalstab[i] = new Dog();

	for (int i = 0; i < size; i++)
		delete Animalstab[i];
	delete Ai;
	delete Aj;

	return (0);
}
