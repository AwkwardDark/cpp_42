/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:04:02 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/14 10:22:48 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	ft_print_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		std::cout << str[i];
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 0;
		while (++i < argc)
			ft_print_upper(argv[i]);
	}
	std::cout << std::endl;
}
