/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:48:00 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 18:04:42 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	frag("Pepe");

	frag.attack("Juan");
	frag.takeDamage(15);
	std::cout << "Pepe health: " << frag.getHealth() << std::endl;
	frag.takeDamage(75);
	std::cout << "Pepe health: " << frag.getHealth() << std::endl;
	frag.takeDamage(9);
	std::cout << "Pepe health: " << frag.getHealth() << std::endl;
	std::cout << "Pepe energy: " << frag.getEnergy() << std::endl;
	frag.attack("Juan");
	frag.attack("Juan");
	frag.attack("Juan");
	frag.attack("Juan");
	frag.attack("Juan");
	frag.attack("Juan");
	std::cout << "Pepe energy: " << frag.getEnergy() << std::endl;
	frag.highFivesGuys();

	return (0);
}
