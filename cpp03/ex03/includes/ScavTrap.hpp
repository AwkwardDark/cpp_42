/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:48:12 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 18:12:06 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap{

		public:
				ScavTrap(void);
				ScavTrap(std::string name);
				~ScavTrap(void);
				ScavTrap(ScavTrap const &src);
				ScavTrap &operator=(ScavTrap const &src);
				void	guardGate(void);
				void	attack(const std::string &target);
				int		getEnergyPoint(void);
};

#endif
