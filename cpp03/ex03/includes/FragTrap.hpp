/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:19:53 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 17:29:37 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ScavTrap.hpp"

class	FragTrap : virtual public ClapTrap{

	public:
			FragTrap(void);
			FragTrap(std::string name);
			~FragTrap(void);
			FragTrap(FragTrap const &src);
			FragTrap &operator=(FragTrap const &src);
			void	highFivesGuys(void);

};

#endif
