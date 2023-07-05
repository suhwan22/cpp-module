/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:56:27 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/05 20:20:05 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	check_target_p_int(char *target)
{
	long long	temp;

	if (!target || !(*target))
		return (false);
	temp = static_cast<long long>(std::strtod(target, NULL));
	if (temp < 1 || temp > 2147483647)
		return (false);
	else
		return (true);
}

bool	check_error(int argc, char **argv)
{
	int	len;
	int	i;

	len = argc;
	while (--len)
	{
		i = 0;
		while (*(*(argv + len) + i))
		{
			if (i == 0 && (**(argv + len) == '+' || **(argv + len) == '-'))
				i++;
			if (!std::isdigit(*(*(argv + len) + i)))
				return (true);
			i++;
		}
		if (!check_target_p_int(*(argv + len)))
			return (true);
	}
	return (false);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage:./PmergeMe <...>" << std::endl;
		return (1);
	}
	if (check_error(argc, argv))
	{
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	PmergeMe p(argc, argv);
	p.run();
	return (0);
}
