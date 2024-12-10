/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:50:46 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 19:50:49 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		Dog(const Dog& obj);
		~Dog();
		Dog&	operator=(const Dog& obj);

		void	makeSound() const;
};

#endif
