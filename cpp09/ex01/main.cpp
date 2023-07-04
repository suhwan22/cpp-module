/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:10:18 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/04 12:34:31 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "please enter : ./RPN <inverted Polish mathematical expression>" << std::endl;
		return (1);
	}
	RPN rpn;
	rpn.runProcess(argv[1]);
	return (0);
}
