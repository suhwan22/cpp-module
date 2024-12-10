/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:50:45 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 19:50:49 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(const Cat& obj);
		~Cat();
		Cat&	operator=(const Cat& obj);

		void	makeSound() const;
};

#endif