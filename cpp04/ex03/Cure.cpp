/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:28:47 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/13 18:39:45 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& obj) : AMateria(obj._type) {}

Cure& Cure::operator=(const Cure& obj)
{
	(void)obj;
	std::cout << "While assigning a Materia to another, copying the type "
		<< "doesn't make sense" << std::endl;
	return (*this);
}

Cure::~Cure() {}

AMateria*	Cure::clone() const
{
	AMateria* newCure = new Cure();

	return (newCure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
