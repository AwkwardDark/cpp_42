/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:48:00 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 18:04:57 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scav("Pepe");

	scav.attack("Juan");
	scav.takeDamage(15);
	std::cout << "Pepe health: " << scav.getHealth() << std::endl;
	scav.takeDamage(75);
	std::cout << "Pepe health: " << scav.getHealth() << std::endl;
	std::cout << "Pepe energy: " << scav.getEnergy() << std::endl;
	scav.attack("Juan");
	scav.attack("Juan");
	scav.attack("Juan");
	scav.attack("Juan");
	scav.attack("Juan");
	scav.attack("Juan");
	std::cout << "Pepe energy: " << scav.getEnergy() << std::endl;
	scav.guardGate();

	return (0);
}
