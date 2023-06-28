/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:36:54 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/29 01:43:24 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int	int_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string	s_arr[7] = {"Monday", "Tuesday", "Wednesday", 
					"Thursday", "Friday", "Saturday", "Sunday"};
	double	d_arr[5] = {1.1, 22.22, 333.333, 4444.4444, 55555.55555};

	iter(int_arr, 10, putElement);
	std::cout << std::endl;
	iter(s_arr, 7, putElement);
	std::cout << std::endl;
	iter(d_arr, 5, putElement);

	return (0);
}
