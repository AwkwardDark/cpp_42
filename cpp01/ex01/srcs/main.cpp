/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:01:09 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 15:30:20 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(10, "Paco");
	for(int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
	return (0);	
}
