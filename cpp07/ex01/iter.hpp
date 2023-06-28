/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:36:54 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/29 01:32:35 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *arr, int len, void (*f)(T&))
{
	int	i;

	i = 0;
	for(; i < len; i++)
		f(arr[i]);
}

template <typename T>
void	putElement(T &target)
{
	std::cout << target << std::endl;
}

#endif
