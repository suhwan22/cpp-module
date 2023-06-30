/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:19:38 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/30 21:04:36 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int i)
{
	typename T::iterator	iter;

	iter = std::find(container.begin(), container.end(), i);
	if (iter == container.end())
		throw std::invalid_argument("container doesn't have your input");
	return (iter);
}


#endif
