/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:28:47 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 18:51:46 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& obj) : AMateria(obj._type) {}

Ice& Ice::operator=(const Ice& obj)
{
	(void)obj;
	std::cout << "While assigning a Materia to another, copying the type "
		<< "doesn't make sense" << std::endl;
	return (*this);
}

Ice::~Ice() {}

AMateria*	Ice::clone() const
{
	AMateria* newIce = new Ice();

	return (newIce);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
