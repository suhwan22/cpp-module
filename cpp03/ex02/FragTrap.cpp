/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:01:54 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/12 17:15:57 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30)
{
	std::cout << "FragTrap " << _name << "has been created by default constructor" 
		<< std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << _name << " has been created"<< std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	*this = obj;
	std::cout << "FragTrap " << _name << " has been created by copy constructor" 
		<< std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " has been destoryed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	std::cout << "copy assignment operator is called" << std::endl;

	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " wants to give a high five!!" 
		<< std::endl;
}
