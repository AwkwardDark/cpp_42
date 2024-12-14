#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void 	identify(Base* p);
void 	identify(Base& p);

int	main(void)
{
	Base *base = generate();

	identify(base);	 // Passing address;
	identify(*base); // Passing reference
	
	delete base;

	return (0);
}
