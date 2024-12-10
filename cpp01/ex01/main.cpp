/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:16:11 by suhkim            #+#    #+#             */
/*   Updated: 2023/02/27 07:53:27 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie*	newZombies = zombieHorde(5, "jerk");

	for (int i = 0; i < 5; i++)
		newZombies[i].announce();

	Zombie*	testZombies = zombieHorde(10, "test");

	for (int i = 0; i < 10; i++)
		testZombies[i].announce();

	delete[] newZombies;
	delete[] testZombies;
	return (0);
}
