/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:52:29 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 19:38:17 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal{

	public:
			Dog(void);
			~Dog(void);
			Dog(Dog const &src);
			Dog &operator=(Dog const &src);
			void	makeSound(void) const;

};

#endif
