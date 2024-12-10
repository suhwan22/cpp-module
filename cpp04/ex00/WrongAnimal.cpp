/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:57:33 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 18:57:37 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default")
{
	std::cout << "WrongAnimal default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	*this = obj;
	std::cout << "WrongAnimal copy constructor is called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << "WrongAnimal assignment operator is called" << std::endl;
	_type = obj._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destuctor is called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "just WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}
