/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 07:45:35 by suhkim            #+#    #+#             */
/*   Updated: 2023/02/27 07:50:14 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	newZombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		newZombies[i].setName(name);
	}
	return (newZombies);
}
