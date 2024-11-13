/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:01:13 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/07 18:25:27 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name)
{
	Zombie *horde;
	
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return (horde);
}
