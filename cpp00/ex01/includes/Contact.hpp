/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:58:51 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/14 12:49:12 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
	private:
			std::string	first_name;
			std::string	last_name;
			std::string	nickname;
			std::string	phone_number;
			std::string darkest_secret;
			int			index;
	public:
			void setFirstName(std::string& name);
			void setLastName(std::string& name);
			void setNickname(std::string& name);
			void setPhoneNumber(std::string& number);
			void setDarkestSecret(std::string& secret);
			void setIndex(int index);
			std::string& getFirstName(void);
			std::string& getLastName(void);
			std::string& getNickname(void);
			std::string& getPhoneNumber(void);
			std::string& getDarkestSecret(void);
			int			 getIndex(void);
};

#endif
