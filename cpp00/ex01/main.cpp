/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:02:39 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/14 15:28:06 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			return (0);
		else if (!cmd.empty())
		 	std::cout << "Invalid command, use only ADD / SEARCH / EXIT" << std::endl;
	}
	return (1);
}
