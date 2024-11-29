/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:22:55 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/28 17:42:47 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class	ClapTrap{

	private:
			std::string	_name;
			int			health;
			int			energy;
			int			damage;
	
	public:
			ClapTrap(void);
			~ClapTrap(void);
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &src);
			ClapTrap &operator=(const ClapTrap &src);
			void			attack(const std::string &target);
			void			takeDamage(unsigned int amount);
			void			beRepaired(unsigned int amount);
			std::string		getName(void) const;
			int				getHealth(void) const;
			int				getEnergy(void) const;
			int				getDamage(void) const;

};

#endif
