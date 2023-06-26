/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:31:21 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/22 16:31:23 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <string>

int main()
{
	std::cout << "---------------Intern make form successfully case---------------" << std::endl;
	{
		Intern	tester;
		AForm	*form1;
		AForm	*form2;
		AForm	*form3;

		form1 = tester.makeForm("shrubbery creation", "home");
		form2 = tester.makeForm("robotomy request", "root");
		form3 = tester.makeForm("presidential pardon", "master");

		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;

		delete form1;
		delete form2;
		delete form3;
	}
	
	std::cout << "---------------Intern fail to make form case---------------" << std::endl;
	{
		Intern	idiot;

		AForm	*form4;

		form4 = idiot.makeForm("naega mowrago haettjji??", "oilnam");

		if (!form4)
			std::cout << "form4 is NULL" << std::endl;
		else	
			std::cout << *form4 << std::endl;
	}
	return (0);
}
