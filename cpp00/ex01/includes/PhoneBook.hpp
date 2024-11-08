/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:58:48 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/14 18:19:38 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <limits>

class PhoneBook {
	private:
			Contact contactList[8];
			int		contact_count;
	public:
			void	add(void);
			void	search(void);
			PhoneBook() {
				contact_count = 0;
			};
};

#endif
