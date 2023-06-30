/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:19:38 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/30 21:15:38 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::cout << "----------------vector case----------------" << std::endl;
	try
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		std::vector<int>::iterator iter = easyfind(vec, 4);
		std::cout << *iter << std::endl;

		iter = easyfind(vec, 7);
		std::cout << *iter << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n----------------list case----------------" << std::endl;
	try
	{
		std::list<int> list1;
		list1.push_back(1);
		list1.push_back(2);
		list1.push_back(3);
		list1.push_back(4);
		list1.push_back(5);

		std::list<int>::iterator iter = easyfind(list1, 4);
		std::cout << *iter << std::endl;

		iter = easyfind(list1, 7);
		std::cout << *iter << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
