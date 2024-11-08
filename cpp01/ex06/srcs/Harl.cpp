/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:25:05 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 19:26:50 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << DEBUG << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << INFO << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << WARNING << std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << ERROR << std::endl << std::endl;
}

int	Harl::get_level_number(std::string level)
{
	std::string level_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (level == level_tab[i])
			return (i);
	}
	return (-1);
}

void	Harl::complain_filter(std::string level)
{
	int	level_number = get_level_number(level);
	
	switch (level_number)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		default:
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