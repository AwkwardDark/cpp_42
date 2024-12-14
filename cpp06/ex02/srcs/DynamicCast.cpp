#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	srand(time(0));
	int	i = rand() % 3;
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	return (new C());
}

// We check systematically if the dynamic_cast succeed during execution
void	identify(Base *p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);
	
	std::cout << "Type of object pointed (address): " << std::endl;
	if (a)
		std::cout << "A" << std::endl;
	if (b)
		std::cout << "B" << std::endl;
	if (c)
		std::cout << "C" << std::endl;
	std::cout << std::endl;
}

/*Because downcast can fail during execution, we need to catch the exception
thrown by the dynamic cast*/
void	identify(Base &p)
{
	std::cout << "Type of object pointed (reference): " << std::endl;
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
