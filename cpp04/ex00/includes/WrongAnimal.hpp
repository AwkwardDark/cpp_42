/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:52:57 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 19:39:21 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class	WrongAnimal{

	protected:
			std::string	type;

	public:
			WrongAnimal(void);
			WrongAnimal(std::string type);
			WrongAnimal(WrongAnimal const &src);
			virtual ~WrongAnimal(void);
			WrongAnimal &operator=(WrongAnimal const &src);
			virtual	void	makeSound(void) const;
			std::string		getType(void) const;
			
};

#endif
