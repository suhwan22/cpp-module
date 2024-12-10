/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:56:17 by suhkim            #+#    #+#             */
/*   Updated: 2023/02/25 08:45:15 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	each_idx = 0;
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	dark_secret = "";
}

Contact::~Contact() {}

std::string Contact::get_first_name() const
{
	return (first_name);
}

std::string Contact::get_last_name() const
{
	return (last_name);
}

std::string Contact::get_nickname() const
{
	return (nickname);
}

std::string Contact::get_phone_number() const
{
	return (phone_number);
}

std::string Contact::get_dark_secret() const
{
	return (dark_secret);
}

int	Contact::get_this_idx() const
{
	return (each_idx);
}


void	Contact::set_first_name(const std::string name)
{
	first_name = name;
}
void	Contact::set_last_name(const std::string name)
{
	last_name = name;
}
void	Contact::set_nickname(const std::string name)
{
	nickname = name;
}
void	Contact::set_phone_number(const std::string nums)
{
	phone_number = nums;
}
void	Contact::set_dark_secret(const std::string secret)
{
	dark_secret = secret;
}

void	Contact::set_this_idx(const int idx)
{
	each_idx = idx;
}
