/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:36:17 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/04 12:32:02 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN& obj) { (void)obj; }

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}


bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	else
		return (false);
}

int		RPN::calculate(std::string& input)
{
	std::stack<int>	stack;

	if (input.empty())
		throw std::runtime_error("Error: empty argument");
	for (std::string::iterator it = input.begin(); it < input.end(); it++)
	{
		if (*it == ' ')
			continue;
		if (std::isdigit(*it))
			stack.push(*it - '0');
		else if (isOperator(*it))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: Insufficient factors for operation.");
			int	n1, n2;
			n1 = stack.top();
			stack.pop();
			n2 = stack.top();
			stack.pop();
			if (*it == '+')
				stack.push(n2 + n1);
			else if (*it == '-')
				stack.push(n2 - n1);
			else if (*it == '*')
				stack.push(n2 * n1);
			else if (*it == '/')
			{
				if (n1 == 0)
					throw std::runtime_error("Error: It is forbidden to divide by zero.");
				stack.push(n2 / n1);
			}
		}
		else
			throw std::runtime_error("Error: invalid argument");
	}
	if (stack.empty())
		throw std::runtime_error("Error: there is no number");
	return (stack.top());
}

void	RPN::runProcess(std::string input)
{
	try
	{
		std::cout << calculate(input) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
