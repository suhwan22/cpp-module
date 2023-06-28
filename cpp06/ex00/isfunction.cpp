/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isfunction.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:18:16 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/28 20:24:53 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.hpp"

bool	isChar(std::string input)
{
	if (input.length() == 1 && !std::isdigit(input.at(0)))
		return (true);
	else
		return (false);
}

bool	isInt(std::string input)
{
	int	i;
	int	len;

	len = input.length();
	if (input.at(0) == '-' || input.at(0) == '+')
		i = 1;
	else
		i = 0;
	for (; i < len; i++)
	{
		if (!std::isdigit(input.at(i)))
			return (false);
	}
	return (true);
}

bool	isFloat(std::string input)
{
	int	i;
	int	len;
	int	point;

	if (input == "+inff" || input == "-inff" || input == "inff" || input == "nanf")
		return (true);
	point = 0;
	if (input.at(0) == '-' || input.at(0) == '+')
		i = 1;
	else
		i = 0;
	len = input.length();
	if (!std::isdigit(input.at(i)))
		return (false);
	for (; i < len - 1; i++)
	{
		if (i == len - 2 && !std::isdigit(input.at(i)))
			return (false);
		if (!(std::isdigit(input.at(i)) || (input.at(i) == '.' && point == 0)))
			return (false);
		if (input.at(i) == '.')
			point = 1;
	}
	if (input.at(i) != 'f')
		return (false);
	if (point)
		return (true);
	return (false);
}

bool	isDouble(std::string input)
{
	int	i;
	int	len;
	int	point;

	if (input == "+inf" || input == "-inf" || input == "inf" || input == "nan")
		return (true);
	point = 0;
	if (input.at(0) == '-' || input.at(0) == '+')
		i = 1;
	else
		i = 0;
	len = input.length();
	if (!std::isdigit(input.at(i)))
		return (false);
	for (; i < len; i++)
	{
		if (!std::isdigit(input.at(len - 1)))
			return (false);
		if (!(std::isdigit(input.at(i)) || (input.at(i) == '.' && point == 0)))
			return (false);
		if (input.at(i) == '.')
			point = 1;
	}
	if (point)
		return (true);
	return (false);
}

Type	detectType(std::string input)
{
	if (isChar(input))
		return(Char);
	else if (isInt(input))
		return (Int);
	else if (isFloat(input))
		return (Float);
	else if (isDouble(input))
		return (Double);
	else
		return (Invalid);
}

