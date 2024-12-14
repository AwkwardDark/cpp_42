#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename T_f>
void	iter(T *array, size_t size, T_f f)
{
	if (!array || !f)
		return ;
	for(size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif
