/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:01:16 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/28 19:58:50 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *	gernerate(void)
{
	int	a;

	srand(time(NULL));
	a = rand() % 3;
	switch(a)
	{
		case 0: std::cout << "gernerate A type" << std::endl;
			return (new A());
		case 1: std::cout << "gernerate B type" << std::endl;
				return (new B());
		case 2: std::cout << "gernerate C type" << std::endl;
				return (new C());
		default: return (nullptr);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "it is A type pointer" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "it is B type pointer" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "it is C type pointer" << std::endl;
	else
		std::cout << "it is not type of Base" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "it is A type reference" << std::endl;
	}
	catch (std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "it is B type reference" << std::endl;
		}
		catch (std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p); std::cout << "it is C type reference" << std::endl;
			}
			catch (std::exception& e)
			{
			}
		}
	}
}

int main()
{
	Base	*test;

	test = gernerate();

	std::cout << "\n\n-------------------pointer case---------------------" << std::endl;
	identify(test);

	std::cout << "\n\n-------------------reference case---------------------" << std::endl;
	identify(*test);

	delete test;
	return (0);
}
