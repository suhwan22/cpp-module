/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:18:16 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/28 18:18:19 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ft.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "bad argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
