/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:24:29 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 18:38:33 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;
	
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments. Format: ./harl <level>" << std::endl;
		std::cout << "Levels are: debug / info / warning / error" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}
