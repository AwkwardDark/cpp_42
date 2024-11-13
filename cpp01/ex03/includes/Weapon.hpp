/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:49:51 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 16:45:41 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
	
	private:
		std::string	_type;

	public:
		const std::string&	getType(void);
		void				setType(std::string type);
		Weapon(std::string type);
		~Weapon();

};

#endif