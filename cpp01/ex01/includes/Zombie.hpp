/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:01:08 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 15:31:24 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie{
	
	private:
		std::string _name;
	public:
		Zombie(void);
		~Zombie(void);
		void	set_name(std::string name);
		void	announce(void);
		
};

Zombie*	zombieHorde(int N, std::string name);

#endif