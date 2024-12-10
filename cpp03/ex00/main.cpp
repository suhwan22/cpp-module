/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:02:08 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/11 18:02:10 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "\n############# Test for orthodox canonical form #############\n";
	{
		ClapTrap	jerk("jerk");
		ClapTrap	test(jerk);
		ClapTrap	temp;
	
		temp = jerk;

		jerk.beRepaired(1);
		test.beRepaired(2);
		temp.beRepaired(3);
	}

	std::cout << "\n############# Test for member functions #############\n";
	{
		ClapTrap	idiot("idiot");
		ClapTrap	jerk("jerk");
		ClapTrap	fool("fool");

		for(int i = 0; i < 10; i++)
		{
			idiot.attack("jerk");
		}
		idiot.attack("fool");
		idiot.beRepaired(1);
		std::cout << std::endl;

		for(int j = 1; j < 7; j++)
			jerk.takeDamage(j);
		jerk.attack("fool");
		jerk.beRepaired(100);
		std::cout << std::endl;

		for(int k = 1; k < 10; k++)
		{
			fool.takeDamage(k);
			fool.beRepaired(3);
		}
		std::cout << std::endl;
	}
	return (0);
}
