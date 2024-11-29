/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:50:12 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 19:43:58 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal{

	protected:
			std::string	_type;

	public:
			Animal(void);
			Animal(std::string type);
			Animal(Animal const &src);
			virtual ~Animal(void);
			Animal &operator=(Animal const &src);
			virtual	void	makeSound(void) const;
			std::string		getType(void) const;
			
};

#endif
