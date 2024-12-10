/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:02:16 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/12 17:14:18 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default", 100, 50, 20)
{
	std::cout << "ScavTrap " << _name << "has been created by default constructor" 
		<< std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << _name << " has been created"<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	*this = obj;
	std::cout << "ScavTrap " << _name << " has been created by copy constructor" 
		<< std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destoryed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	std::cout << "copy assignment operator is called" << std::endl;

	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack because " 
			<< _name << " is already dead" << std::endl;
	}
	else if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack because " << _name 
			<< " has no enough energy points" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " 
			<< _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode" 
		<< std::endl;
}
