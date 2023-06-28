/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:43:25 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/28 18:18:19 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ft.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj) { (void)obj; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	if (this == &obj)
		return (*this);
	else
	{
		return (*this);
	}
}

void	ScalarConverter::convert(std::string value)
{
	Type	_type;

	_type = detectType(value);
	doProcess(_type, value);
}
