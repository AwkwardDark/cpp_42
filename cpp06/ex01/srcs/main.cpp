#include "Serializer.hpp"

int	main(void)
{
	Data	spider;
	spider.type = "arthropod";
	spider.legs = 8;

	std::cout << "Data address:         " << &spider << std::endl;
	uintptr_t int_ptr = Serializer::serialize(&spider);
	std::cout << "Pointer integer:      " << int_ptr << std::endl;
	Data *data_ptr = Serializer::deserialize(int_ptr);
	std::cout << "Deserialized address: " << data_ptr << std::endl << std::endl;

	std::cout << "animal type: " << data_ptr->type << ", has: " << data_ptr->legs << " legs" << std::endl;

	return (0);
}
