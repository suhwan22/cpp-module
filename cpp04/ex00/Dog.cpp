/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:57:32 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 18:57:37 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor is called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
	std::cout << "Dog copy constructor is called" << std::endl;
	*this = obj;
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called" << std::endl;
}

Dog&	Dog::operator=(const Dog& obj)
{
	std::cout << "Dog copy assignment operator is called" << std::endl;
	_type = obj._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "woof! woof!" << std::endl;
}
