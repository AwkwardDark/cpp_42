#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer constructor called" << std::endl;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called" << std::endl;
}

Serializer::Serializer(Serializer const &src)
{
	(void)src;
	std::cout << "Serializer copy constructor called" << std::endl;
}

Serializer &Serializer::operator=(Serializer const &src)
{
	(void)src;
	return (*this);
}

// Downcast
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t int_ptr = reinterpret_cast<uintptr_t>(ptr);
	return (int_ptr);
}

// Upcast
Data* Serializer::deserialize(uintptr_t raw)
{
	Data* data_ptr = reinterpret_cast<Data *>(raw);
	return (data_ptr);
}
