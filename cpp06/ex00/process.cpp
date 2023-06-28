/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:18:16 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/28 18:18:19 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.hpp"

void	charProcess(std::string input)
{
	char	value;

	value = static_cast<char>(input.at(0));
	if (std::isprint(value))
		std::cout << "char: '" << value << "'" << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void	intProcess(std::string input)
{
	int		value;
	double	dinput;

	dinput = std::strtod(input.c_str(), NULL);
	value = static_cast<int>(dinput);

	if (dinput >= std::numeric_limits<char>::max() + 1.0 \
			|| dinput <= std::numeric_limits<char>::min() - 1.0)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(dinput))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(dinput) << "'" << std::endl;

	if (dinput > std::numeric_limits<int>::min() - 1.0 \
			&& dinput < std::numeric_limits<int>::max() + 1.0)
		std::cout << "int: " << value << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (dinput != dinput)
		std::cout << "float: nanf" << std::endl;
	else if (dinput == std::numeric_limits<float>::infinity())
		std::cout << "float: +inff" << std::endl;
	else if (dinput == -std::numeric_limits<float>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (dinput > std::numeric_limits<float>::max() \
			&& dinput < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(dinput) << 'f' << std::endl;

	if (dinput != dinput)
		std::cout << "double: nan" << std::endl;
	else if (dinput == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else if (dinput == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << dinput << std::endl;
}

void	floatProcess(std::string input)
{
	float	value;
	double	dinput;

	dinput = std::strtod(input.c_str(), NULL);
	value = static_cast<float>(dinput);

	if (dinput >= std::numeric_limits<char>::max() + 1.0  \
			|| dinput <= std::numeric_limits<char>::min() - 1.0 || input == "nan" || input == "nanf")
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(dinput))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(dinput) << "'" << std::endl;

	if (dinput > std::numeric_limits<int>::min() - 1.0 \
			&& dinput < std::numeric_limits<int>::max() + 1.0)
		std::cout << "int: " << static_cast<int>(dinput) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (dinput != dinput)
		std::cout << "float: nanf" << std::endl;
	else if (dinput == std::numeric_limits<float>::infinity())
		std::cout << "float: +inff" << std::endl;
	else if (dinput == -std::numeric_limits<float>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (dinput > std::numeric_limits<float>::max() \
			&& dinput < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << 'f' << std::endl;

	if (dinput != dinput)
		std::cout << "double: nan" << std::endl;
	else if (dinput == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else if (dinput == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << dinput << std::endl;
}

void	doubleProcess(std::string input)
{
	double	value;

	value = std::strtod(input.c_str(), NULL);

	if (value >= std::numeric_limits<char>::max() + 1.0  \
			|| value <= std::numeric_limits<char>::min() - 1.0 || input == "nan" || input == "nanf")
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(value))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	if (value > std::numeric_limits<int>::min() - 1.0 \
			&& value < std::numeric_limits<int>::max() + 1.0)
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (value != value)
		std::cout << "float: nanf" << std::endl;
	else if (value == std::numeric_limits<float>::infinity())
		std::cout << "float: +inff" << std::endl;
	else if (value == -std::numeric_limits<float>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (value > std::numeric_limits<float>::max() \
			&& value < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << 'f' << std::endl;

	if (value != value)
		std::cout << "double: nan" << std::endl;
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void	invalidProcess()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	doProcess(Type _type, std::string input)
{
	switch(_type)
	{
		case Char: charProcess(input);
			break;
		case Int: intProcess(input);
			break;
		case Double: doubleProcess(input);
			break;
		case Float: floatProcess(input);
			break;
		default: invalidProcess();
			return ;
	}
}
