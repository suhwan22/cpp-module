/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:02:31 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/11 18:20:34 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::cout << "\n############# Test for orthodox canonical form #############\n";
	{
		FragTrap	jerk("jerk");
		FragTrap	test(jerk);
		FragTrap	temp;
	
		temp = jerk;

		jerk.beRepaired(1);
		test.beRepaired(2);
		temp.beRepaired(3);
	}

	std::cout << "\n############# Test for member functions #############\n";
	{
		FragTrap	idiot("idiot");
		FragTrap	jerk("jerk");
		FragTrap	fool("fool");

		idiot.highFivesGuys();
		for(int i = 0; i < 100; i++)
		{
			idiot.attack("jerk");
		}
		idiot.attack("fool");
		idiot.beRepaired(1);
		std::cout << std::endl;

		for(int j = 1; j < 7; j++)
			jerk.takeDamage(10 * j);
		jerk.attack("fool");
		jerk.beRepaired(100);
		std::cout << std::endl;

		for(int k = 1; k < 10; k++)
		{
			fool.takeDamage(10 * k);
			fool.beRepaired(30);
		}
		std::cout << std::endl;
	}
	return (0);
}
