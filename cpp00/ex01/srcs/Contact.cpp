/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:58:52 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 14:55:31 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string& name)
{
	first_name = name;
}

void	Contact::setLastName(std::string& name)
{
	last_name = name;
}

void	Contact::setNickname(std::string& name)
{
	nickname = name;
}

void	Contact::setPhoneNumber(std::string& number)
{
	phone_number = number;
}

void	Contact::setDarkestSecret(std::string& secret)
{
	darkest_secret = secret;
}

void	Contact::setIndex(int number)
{
	index = number;
}

std::string&	Contact::getFirstName(void)
{
	return(first_name);
}

std::string& Contact::getLastName(void)
{
	return(last_name);
}

std::string& Contact::getNickname(void)
{
	return (nickname);
}

std::string& Contact::getPhoneNumber(void)
{
	return (phone_number);
}

std::string& Contact::getDarkestSecret(void)
{
	return (darkest_secret);
}

int			Contact::getIndex(void)
{
	return (index);
}
