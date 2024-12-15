#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mstack;

	// Creating the stack and showing the elements
	srand(time(0));
	std::cout << "Stack elements:" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		mstack.push(rand() % 20);
		std::cout << mstack.top() << "  ";
	}
	std::cout << std::endl << std::endl;

	// Testing iterator
	std::cout << "Normal iterator:" << std::endl;
	MutantStack<int>::iterator itb = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	for (; itb != ite; itb++)
		std::cout << *itb << "  ";
	std::cout << std::endl << std::endl;

	// Testing reverse iterator
	std::cout << "Reverse iterator:" << std::endl;
	MutantStack<int>::reverse_iterator itrb = mstack.rbegin();
	MutantStack<int>::reverse_iterator itre = mstack.rend();
	for (; itrb != itre; itrb++)
		std::cout << *itrb << "  ";
	std::cout << std::endl;

	// stack container adaptor hasn't a default iterator, it's contained on its
	// protected attribute, onlty possible to use by class that heritates std::stack
	//std::stack<int>	s;
	//s.begin();

	return (0);
}

// Subject main
// int main(void)
// {
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << mstack.top() << std::endl;

// 	mstack.pop();

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();

// 	++it;
// 	--it;

// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);

// 	return (0);
// }