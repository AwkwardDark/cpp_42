/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:23:07 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/08 19:18:12 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define INFO "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more"
# define WARNING "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
# define ERROR "This is unacceptable! I want to speak to the manager now."

class	Harl{

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		void	complain_filter(std::string level);
		int		get_level_number(std::string level);
		Harl();
		~Harl();

};

#endif