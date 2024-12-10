/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:16:11 by suhkim            #+#    #+#             */
/*   Updated: 2023/02/26 23:42:27 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	zombie("jerk");
	zombie.announce();

	Zombie*	testZombie = newZombie("test");
	testZombie->announce();

	randomChump("Chump");

	delete testZombie;

	return (0);
}
