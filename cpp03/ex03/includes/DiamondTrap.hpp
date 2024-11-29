/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:44:57 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 16:58:11 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap , public FragTrap{

	private:
			std::string	_name;

	public:
			DiamondTrap(void);
			~DiamondTrap(void);
			DiamondTrap(DiamondTrap const &src);
			DiamondTrap(std::string _name);
			DiamondTrap &operator=(DiamondTrap const &src);
			void		attack(std::string const &target);
			void		whoAmI(void);

};

#endif
