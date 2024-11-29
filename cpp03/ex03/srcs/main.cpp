/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:48:00 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 18:05:47 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamond("Pepe");

	std::cout << "Pepe energy: " << diamond.getEnergy() << std::endl;
	diamond.attack("Juan");
	std::cout << "Pepe health: " << diamond.getHealth() << std::endl;
	diamond.takeDamage(55);
	std::cout << "Pepe health: " << diamond.getHealth() << std::endl;
	diamond.takeDamage(25);
	std::cout << "Pepe health: " << diamond.getHealth() << std::endl;
	diamond.attack("Juan");
	diamond.attack("Juan");
	diamond.attack("Juan");
	diamond.attack("Juan");
	diamond.attack("Juan");
	diamond.attack("Juan");
	std::cout << "Pepe energy: " << diamond.getEnergy() << std::endl;
	diamond.whoAmI();

	return (0);
}
