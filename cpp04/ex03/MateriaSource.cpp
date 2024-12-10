/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:39:31 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/13 18:53:43 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_sources[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj._sources[i] != NULL)
			_sources[i] = obj._sources[i]->clone();
		else
			_sources[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (_sources[i] != NULL)
			delete _sources[i];
		if (obj._sources[i] != NULL)
			_sources[i] = obj._sources[i]->clone();
		else
			_sources[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	int	dup = 0;

	for (int i = 0; i < 4; i++)
	{
		if (_sources[i] != NULL)
		{
			for (int j = 0; j < i; j++)
				if (_sources[j] == _sources[i])
					dup = 1;
			if (!dup)
				delete _sources[i];
			dup = 0;
		}
	}
}

void		MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_sources[i] == NULL)
		{
			_sources[i] = m;
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_sources[i] != NULL && _sources[i]->getType() == type)
			return _sources[i]->clone();
	}
	return (NULL);
}
