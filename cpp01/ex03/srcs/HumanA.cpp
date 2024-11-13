/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:51:15 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 17:15:55 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
}
void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this->_name << " instance destroyed" << std::endl;
}
