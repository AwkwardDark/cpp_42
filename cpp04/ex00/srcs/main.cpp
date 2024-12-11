#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// Initialize
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	// Testing sound
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); // will output Dog sound
	meta->makeSound();
	std::cout << std::string(30, '-') << std::endl;	

	// Assignement operator
 	const Dog* dog = new Dog();
	const Cat* cat = new Cat();
	const Dog* copyDog = dog;
	const Cat* copyCat = cat;
	cat->makeSound(); // will output cat sound
	dog->makeSound(); // will output Dog sound 
	std::cout << "copyCat type: " << copyCat->getType() << std::endl;
	std::cout << "copyDog type: " << copyDog->getType() << std::endl;
	copyCat->makeSound(); // will output cat sound
	copyDog->makeSound(); // will output Dog sound
	std::cout << std::string(30, '-') << std::endl;	

	// Copy constructor
 	Animal copy(*dog);
	std::cout << "copyDog type: "<< copy.getType() << std::endl;
	copy.makeSound();
	std::cout << std::string(30, '-') << std::endl;	

	//Testing the "wrong" classes
	const WrongAnimal* metabis = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	k->makeSound(); // will output the Wrongcat sound
	metabis->makeSound(); // will output the "generic Wronganimal" sound

	// Free
	delete dog;
	delete cat;
	delete meta;
	delete i;
	delete j;
	delete k;
	delete metabis;

	return (0);
}
