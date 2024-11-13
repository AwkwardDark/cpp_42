/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:12:48 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 15:28:48 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

	private:
		std::string	_name;
	public:
		void	announce(void);
		Zombie(std::string	name);
		~Zombie();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif