/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:59:53 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/13 18:39:45 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("NULL") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& obj) : _type(obj._type) {}

AMateria&	AMateria::operator=(const AMateria& obj)
{
	_type = obj._type;
	return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "base class use() is called, you mean? " << std::endl;
}
