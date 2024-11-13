/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:49:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 16:53:45 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB{

	private:
		std::string	_name;
		Weapon		*_weapon;
	
	public:
		void		attack();
		void		setWeapon(Weapon &weapon);
		HumanB(std::string name);
		~HumanB(void);
};

#endif