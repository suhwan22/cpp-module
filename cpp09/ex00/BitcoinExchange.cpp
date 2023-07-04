/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 05:11:56 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/04 11:05:23 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	_csvData = obj._csvData;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	if (this == &obj)
		return (*this);
	_csvData = obj._csvData;
	return (*this);
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date.find_first_of(" \t", 0) != std::string::npos)
		return (false);

	int	y, m, d;
	char	c1, c2;
	std::stringstream	ss(date);

	ss >> y >> c1 >> m >> c2 >> d;
	if (ss.fail() || !ss.eof())
		return (false);
	if (c1 != '-' || c2 != '-')
		return (false);
	if (y < 1 || m < 1 || d < 1 || m > 12)
		return (false);

	int	maxDay;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		maxDay = 31;
	else if (m == 2)
		maxDay = (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) ? 29 : 28;
	else
		maxDay = 30;

	if (d > maxDay)
		return (false);
	return (true);
}

bool	BitcoinExchange::isValidValue(const std::string& value)
{
	std::stringstream	ss(value);
	float	fvalue;

	ss >> fvalue;
	if (ss.fail() || !ss.eof() || value.find_first_of(" \t", 0) != std::string::npos)
	{
		std::cout << "Error: value is not valid." << std::endl;
		return (false);
	}
	if (fvalue < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (fvalue > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);

}

bool	BitcoinExchange::addData(std::string& line)
{
	std::stringstream ss(line);
	std::string	key;
	float		value;

	std::getline(ss, key, ',');
	ss >> value;
	if (ss.fail() || !ss.eof())
		return (false);
	if (!isValidDate(key))
		return (false);
	if (value < 0)
		return (false);
	_csvData[key] = value;
	return (true);
}

void	BitcoinExchange::csvParse()
{
	std::ifstream	csvFile("data.csv");
	if (!csvFile.is_open())
		throw std::runtime_error("Error: csv file couldn't open");
	//empty file process? is necessary?
	
	std::string	line;
	std::getline(csvFile, line);
	if (line != "date,exchange_rate")
	{
		csvFile.close();
		throw std::runtime_error("Error: Invalid csv file");
	}
	while (std::getline(csvFile, line))
	{
		if (!addData(line))
		{
			csvFile.close();
			throw std::runtime_error("Error: Invalid csv file");
		}
	}
	csvFile.close();
}

void	BitcoinExchange::doExchange(const std::string& date, const std::string& value)
{
	float	mul;
	float	fvalue = std::strtod(value.c_str(), NULL);
	std::map<std::string, float>::iterator	iter = _csvData.find(date);
	if (iter != _csvData.end())
		mul = iter->second;
	else
	{
		iter = _csvData.lower_bound(date);
		if (iter == _csvData.begin())
			mul = iter->second;
		else
			mul = (--iter)->second;
	}
	std::cout << date << " => " << value << " = " << mul * fvalue << std::endl;
}

void	BitcoinExchange::inputParse(const char *input)
{
	std::ifstream	inputFile(input);
	if (!inputFile.is_open())
		throw std::runtime_error("Error: input file couldn't open");

	std::string	line;
	std::getline(inputFile, line);
	if (line != "date | value")
	{
		inputFile.close();
		throw std::runtime_error("Error: input file has invalid header(it isn't \"date | value\".)");
	}

	std::string	date;
	std::string	bar;
	std::string	value;
	while (std::getline(inputFile, line))
	{
		if (line.empty())
			continue;
		if (line.length() < 14)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, 10);
		bar = line.substr(10, 3);
		value = line.substr(13, line.length() - 13);
		if (bar != " | " || !isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!isValidValue(value))
			continue;
		doExchange(date, value);
	}

}

void	BitcoinExchange::runExchange(char *input)
{
	try
	{
		csvParse();
		inputParse(input);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
