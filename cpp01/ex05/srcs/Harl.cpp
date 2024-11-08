/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:25:05 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 19:24:01 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << DEBUG << std::endl;
}

void Harl::info(void)
{
	std::cout << INFO << std::endl;
}

void Harl::warning(void)
{
	std::cout << WARNING << std::endl;
}

void Harl::error(void)
{
	std::cout << ERROR << std::endl;
}

void Harl::complain(std::string level)
{
	std::string level_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int	i = -1;

	while (++i < 4)
	{
		if (level == level_tab[i])
		{
			(this->*function[i])();
			break ;
		}
	}
	if (i == 4)
	{
		std::cout << "Unknown level" << std::endl << "Levels are: DEBUG / INFO / WARNING / ERROR" << std::endl;
	}
}

Harl::Harl(void)
{
	std::cout << "Harls constructor called" << std::endl << std::endl;
}

Harl::~Harl(void)
{
	std::cout << std::endl << "Harls destructor called" << std::endl;
}