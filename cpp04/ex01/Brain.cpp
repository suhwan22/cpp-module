/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:04:54 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 19:12:11 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constuctor is called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Default";
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain copy constructor is called" << std::endl;
	*this = obj;
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called" << std::endl;
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = obj._ideas[i];
	return (*this);
}

void	Brain::setEqualIdeas(std::string ideas)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = ideas;
}

std::string	Brain::getIndexIdeas(const unsigned int idx)
{
	return (_ideas[idx]);
}
