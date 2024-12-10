/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:04:54 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 19:17:45 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor is called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& obj)
{
	std::cout << "Cat copy constructor is called" << std::endl;
	_brain = new Brain();
	_brain->setEqualIdeas(obj._brain->getIndexIdeas(0));
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called" << std::endl;
	delete _brain;
}

Cat&	Cat::operator=(const Cat& obj)
{
	std::cout << "Cat copy assignment operator is called" << std::endl;
	_type = obj._type;
	delete _brain;
	_brain = new Brain();
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow~~ Meow~~" << std::endl;
}
