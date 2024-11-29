/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:39:45 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 18:05:12 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Pepe");

	clap.attack("Juan");
	clap.takeDamage(5);
	std::cout << "Pepe health: " << clap.getHealth() << std::endl;
	clap.takeDamage(5);
	std::cout << "Pepe health: " << clap.getHealth() << std::endl;
	clap.attack("Juan");
	
	return (0);
}
