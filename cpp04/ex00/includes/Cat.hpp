/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:51:42 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 19:38:12 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal{

	public:
			Cat(void);
			~Cat(void);
			Cat(Cat const &src);
			Cat &operator=(Cat const &src);
			void	makeSound(void) const;

};

#endif

