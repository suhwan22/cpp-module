/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:54:54 by suhkim            #+#    #+#             */
/*   Updated: 2023/02/25 09:08:32 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout << ">>>>>>>>>>>>>>>>>>PhoneBook<<<<<<<<<<<<<<<<<<" << std::endl;
	while(1)
	{
		std::cout << "available command : ADD SEARCH EXIT" << std::endl;
		std::cout << "please enter command : ";
		std::getline(std::cin, input);
		if (std::cin.fail())
		{
			std::cout << std::endl;
			exit(1);
		}
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
			break;
		else
			phonebook.print_err_input();
	}
	return (0);
}
