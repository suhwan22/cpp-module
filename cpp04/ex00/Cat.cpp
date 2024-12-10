/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:57:31 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 18:57:37 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor is called" << std::endl;
}

Cat::Cat(const Cat& obj)
{
	std::cout << "Cat copy constructor is called" << std::endl;
	*this = obj;
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called" << std::endl;
}

Cat&	Cat::operator=(const Cat& obj)
{
	std::cout << "Cat copy assignment operator is called" << std::endl;
	_type = obj._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow~~ Meow~~" << std::endl;
}
