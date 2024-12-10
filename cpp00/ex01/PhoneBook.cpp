/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:56:16 by suhkim            #+#    #+#             */
/*   Updated: 2023/02/25 09:15:37 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
	number_of_contact = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::print_err_input() const
{
	std::cout << "\ninput is not valid. please enter repeat\n" << std::endl;
}

int	PhoneBook::get_num() const
{
	return (number_of_contact);
}

void	PhoneBook::add_number_of_contact()
{
	number_of_contact++;
}

int		PhoneBook::ft_getline(std::string str, std::string& target)
{
	std::string	line;
	std::string	include;

	include = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::cout << str;
	std::getline(std::cin, line);
	if (std::cin.fail())
	{
		std::cout << std::endl;
		exit(1);
	}
	if (line.length() == 0 || line.find_first_not_of(include) != std::string::npos)
		return (0);
	target = line;
	return (1);
}

int	PhoneBook::find_oldest_contact() const
{
	int	oldest_idx;
	int	oldest_contact_idx;

	oldest_idx = contacts[0].get_this_idx();
	oldest_contact_idx = 0;
	for (int i = 1; i < 8; i++)
	{
		if (oldest_idx > contacts[i].get_this_idx())
		{
			oldest_idx = contacts[i].get_this_idx();
			oldest_contact_idx = i;
		}
	}
	return (oldest_contact_idx);
}

std::string	PhoneBook::set_ten(std::string str) const
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

void	PhoneBook::show_sum_info() const
{
	std::cout << std::endl;
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "firstname" << "|";
	std::cout << std::setw(10) << "lastname" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) \
			<< set_ten(contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) \
			<< set_ten(contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) \
			<< set_ten(contacts[i].get_nickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::show_detail_info(int idx) const
{
	std::cout << std::endl;
	std::cout << "First name : " << contacts[idx].get_first_name() << std::endl;
	std::cout << "Last name : " << contacts[idx].get_last_name() << std::endl;
	std::cout << "Nick name : " << contacts[idx].get_nickname() << std::endl;
	std::cout << "Phone number : " << contacts[idx].get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << contacts[idx].get_dark_secret() << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::add_contact()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
	int			idx;

	if (number_of_contact < 8)
		idx = number_of_contact;
	else
		idx = find_oldest_contact();
	if (ft_getline("Enter first name : ", first_name) &&
		ft_getline("Enter last name : ", last_name) &&
		ft_getline("Enter nickname : ", nickname) &&
		ft_getline("Enter phone number : ", phone_number) &&
		ft_getline("Enter darkest secret : ", darkest_secret))
	{
		contacts[idx].set_first_name(first_name);
		contacts[idx].set_last_name(last_name);
		contacts[idx].set_nickname(nickname);
		contacts[idx].set_phone_number(phone_number);
		contacts[idx].set_dark_secret(darkest_secret);
		contacts[idx].set_this_idx(get_num());
		add_number_of_contact();
	}
	else
		std::cout << "\nit's not valid\n" << std::endl;
}

void	PhoneBook::search_contact()
{
	std::string	input;

	show_sum_info();
	std::cout << "Enter index :";
	getline(std::cin, input);
	if (std::cin.fail())
	{
		std::cout << std::endl;
		exit(1);
	}
	if (input.length() != 1)
	{
		std::cout << "\nindex is not valid\n" << std::endl;
		return ;
	}
	if (input[0] >= '0' && input[0] <= '7')
	{
		if (input[0] - '0' < number_of_contact)
			show_detail_info(input[0] - '0');
		else
			std::cout << "\nthe contact for that index is empty\n" << std::endl;
	}
	else
		std::cout << "\nindex is not valid\n" << std::endl;
}
