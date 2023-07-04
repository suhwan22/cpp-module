/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:42:22 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/04 10:44:16 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "you have to execute btc with <filename>" << std::endl;
		return (1);
	}
	BitcoinExchange	btc;
	btc.runExchange(argv[1]);
	return (0);
}
