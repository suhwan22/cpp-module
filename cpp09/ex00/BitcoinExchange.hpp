/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 05:11:56 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/04 10:40:56 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _csvData;

		bool	isValidDate(const std::string& date);
		bool	isValidValue(const std::string& value);
		bool	addData(std::string& line);
		void	csvParse();
		void	doExchange(const std::string& date, const std::string& value);
		void	inputParse(const char *input);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& obj);

		void	runExchange(char *input);
};

#endif
