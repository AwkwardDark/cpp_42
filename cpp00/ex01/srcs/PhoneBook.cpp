/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:44:47 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 15:14:46 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	display_format(std::string str)
{
	if (str.length() < 10)
		return (str);
	else
	{
		str = str.substr(0, 10);
		str[9] = '.';
	}
	return (str);
}

void	PhoneBook::add(void)
{
	std::string	input;
	Contact		contact;
	static int	index = 0;
	
	std::cout << "Enter first name :" << std::endl;
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	contact.setFirstName(input);
	std::cout << "Enter last name :" << std::endl;
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	contact.setLastName(input);
	std::cout << "Enter nickname :" << std::endl;
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	contact.setNickname(input);
	std::cout << "Enter phone number :" << std::endl;
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	contact.setPhoneNumber(input);
	std::cout << "Enter darkest secret :" << std::endl;
	std::cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	contact.setDarkestSecret(input);
	contact.setIndex(index);
	contactList[index] = contact;
	if (index == 7)
		index = 0;
	else
		index++;
	if (contact_count < 8)
		contact_count++;
	std::cout << "Contact succefully saved! :)" << std::endl;
}

void	PhoneBook::search(void)
{
	int	index;

	if (contact_count == 0)
	{
		std::cout << "There isn't any contact currently" << std::endl;
		return ;
	}
	for(int i = 0; i < contact_count; i++)
	{
		std::cout << std::setw(10) << std::right << contactList[i].getIndex() << "|";
		std::cout << std::setw(10) << std::right << display_format(contactList[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << display_format(contactList[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << display_format(contactList[i].getNickname()) << std::endl;
	}
	std::cout << "Select and index to show more information about the contact" << std::endl;
	std::cin >> index;
	if (index >= contact_count || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "This contact index doesn't exist, make sure it's displayed on the list above" << std::endl;
		return ;
	}
	std::cout << "First name:     " << contactList[index].getFirstName() << std::endl;
	std::cout << "Last name:      " << contactList[index].getLastName() << std::endl;
	std::cout << "Nickname:       " << contactList[index].getNickname() << std::endl;
	std::cout << "Phone number:   " << contactList[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contactList[index].getDarkestSecret() << std::endl;
}
