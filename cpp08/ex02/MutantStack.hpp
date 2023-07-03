/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:14:15 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/03 21:14:17 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& obj);
		MutantStack& operator=(const MutantStack& obj);
		~MutantStack();

		typedef typename MutantStack<T>::stack::container_type::iterator				iterator;
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator		reverse_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_iterator			const_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator	begin();
		iterator	end();

		reverse_iterator	rbegin();
		reverse_iterator	rend();

		const_iterator	begin() const;
		const_iterator	end() const;

		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

template <typename T>
MutantStack<T>::MutantStack() {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& obj) : std::stack<T>(obj) {}

template <typename T>
MutantStack<T>::~MutantStack() {};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& obj)
{
	if (this == &obj)
		return (*this);
	std::stack<T>::operator=(obj);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}
#endif
