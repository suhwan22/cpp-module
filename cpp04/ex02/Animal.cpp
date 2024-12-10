/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:50:44 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 19:50:49 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default")
{
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor is called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	*this = obj;
	std::cout << "Animal copy constructor is called" << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	std::cout << "Animal copy assignment operator is called" << std::endl;
	_type = obj._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destuctor is called" << std::endl;
}

std::string	Animal::getType() const
{
	return (_type);
}
