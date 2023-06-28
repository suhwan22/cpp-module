/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 23:17:58 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/28 23:23:19 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(T &a, T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T	max(T &a, T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
