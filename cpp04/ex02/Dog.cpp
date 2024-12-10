/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:50:46 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 19:50:49 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor is called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& obj)
{
	std::cout << "Dog copy constructor is called" << std::endl;
	_brain = new Brain();
	_brain->setEqualIdeas(obj._brain->getIndexIdeas(0));
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called" << std::endl;
	delete _brain;
}

Dog&	Dog::operator=(const Dog& obj)
{
	std::cout << "Dog copy assignment operator is called" << std::endl;
	_type = obj._type;
	delete _brain;
	_brain = new Brain();
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "woof! woof!" << std::endl;
}
