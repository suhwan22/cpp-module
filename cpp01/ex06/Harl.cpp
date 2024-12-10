/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:07:51 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/06 17:07:56 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl; 
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << std::endl;
	std::cout << "You didn’t putenough bacon in my burger!";
	std::cout << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << std::endl;
	std::cout << "I've been coming for years whereas you started working" \
		<< "here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*func[4])(void) = {&Harl::debug, &Harl::info, \
		&Harl::warning, &Harl::error};
	std::string name[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (name[i] == level)
		{
			(this->*func[i])();
			return;
		}
	}
	std::cout << "please input valid complain level" << std::endl;
}

void	Harl::filter(std::string level)
{
	Level input = level == "DEBUG" ? DEBUG :
				level == "INFO" ? INFO :
				level == "WARNING" ? WARNING :
				level == "ERROR" ? ERROR : DEFAULT;
	switch(input)
	{
		case DEBUG:
			complain("debug");
			std::cout << std::endl;
		case INFO:
			complain("info");
			std::cout << std::endl;
		case WARNING:
			complain("warning");
			std::cout << std::endl;
		case ERROR:
			complain("error");
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
				<< std::endl;
			break;
	}
}
