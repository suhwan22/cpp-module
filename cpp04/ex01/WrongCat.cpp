/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:04:56 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 19:05:00 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << "WrongCat copy constructor is called" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& obj)
{
	std::cout << "WrongCat assignment operator is called" << std::endl;
	_type = obj._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow~~ Meow~~" << std::endl;
}
