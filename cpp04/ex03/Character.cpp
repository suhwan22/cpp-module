/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:39:28 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 18:52:54 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default"), _ground()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name), _ground()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& obj)
{
	_name = obj._name;
	_ground = obj._ground;
	for (int i = 0; i < 4; i++)
	{
		if (obj._inventory[i] != NULL)
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& obj)
{
	_name = obj._name;
	_ground = obj._ground;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
		if (obj._inventory[i] != NULL)
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	int	dup = 0;

	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			for (int j = 0; j < i; j++)
				if (_inventory[j] == _inventory[i])
					dup = 1;
			if (!dup)
				delete _inventory[i];
			dup = 0;
		}
	}
}

std::string	const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return;

	_ground.addNode(_inventory[idx]);
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return;
	_inventory[idx]->use(target);
}
