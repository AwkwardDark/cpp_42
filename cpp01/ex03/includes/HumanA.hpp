/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:48:47 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 16:53:37 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA{

	private:
		std::string	_name;
		Weapon		&_weapon;
	
	public:
		void		attack();
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
};

#endif