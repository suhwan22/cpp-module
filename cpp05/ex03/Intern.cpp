/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:36:35 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/22 17:08:08 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj) { *this = obj; }

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& obj)
{
	if (this == &obj)
		return (*this);
	else
	{
		return (*this);
	}
}

AForm *Intern::makeForm(std::string formType, std::string target)
{
	std::string	formTypes[3] = {"robotomy request",
								"presidential pardon",
								"shrubbery creation"};
	int	i;
	
	for (i = 0; i < 3; i++)
	{
		if (formType == formTypes[i])
			break ;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << formType << std::endl;
			return (new RobotomyRequestForm(target));
			break ;
		case 1:
			std::cout << "Intern creates " << formType << std::endl;
			return (new PresidentialPardonForm(target));
			break ;
		case 2:
			std::cout << "Intern creates " << formType << std::endl;
			return (new ShrubberyCreationForm(target));
			break ;
		default:
			std::cerr << formType << " is incorrect formType. Intern can't make form" << std::endl;
			return (NULL);
	}
}
