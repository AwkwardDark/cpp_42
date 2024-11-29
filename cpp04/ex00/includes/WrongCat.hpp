/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:53:33 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 19:40:26 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal{

	public:
			WrongCat(void);
			~WrongCat(void);
			WrongCat(WrongCat const &src);
			WrongCat &operator=(WrongCat const &src);
			void	makeSound(void) const;

};

#endif
