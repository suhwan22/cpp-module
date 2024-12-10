/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:02:29 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/12 17:15:15 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Clap Trap " << _name << " has been created by default constructor"
		<< std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage)
	: _name(name),
	_hitPoints(hitPoints),
	_energyPoints(energyPoints),
	_attackDamage(attackDamage)
{
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	*this = obj;
	std::cout << "ClapTrap " << _name << " has been created by copy constructor" 
		<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "copy assignment operator is called" << std::endl;
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;

	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack because " 
			<< _name << " is already dead" << std::endl;
	}
	else if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack because " << _name 
			<< " has no enough energy points" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
			<< _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
	}
	else if (_hitPoints <= amount)
	{
		std::cout << "ClapTrap " << _name << " is dead because of attack" 
			<< std::endl;
		_hitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount 
			<< " points of damage" << std::endl;
		_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired because " 
			<< _name << " is already dead" << std::endl;
	}
	else if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired because "
			<< _name << " has no enough energy points" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " is repaired by " 
			<< amount << " hitpoints" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}
