/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:12:38 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/07 17:58:53 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	Zombie;
	
	std::cout << "Entering randomChump()" << std::endl << std::string(30, '-') << std::endl;
	randomChump("Stack");
	std::cout << std::string(30, '-') << std::endl << "Exiting randomChump()" << std::endl << std::endl;
	std::cout << "Entering newZombie()" << std::endl << std::string(30, '-') << std::endl;
	Zombie = newZombie("Heap");
	delete Zombie;
	std::cout << std::string(30, '-') << std::endl << "Exiting newZombie()" << std::endl;
	return (0);
}
