/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:01:12 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 15:31:51 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

Zombie::Zombie(void)
{
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destroyed" << std::endl;
}
