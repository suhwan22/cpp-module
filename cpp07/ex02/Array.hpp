/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:45:25 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/29 05:45:37 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T*				_arr;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& obj);
		~Array();
		Array&	operator=(const Array& obj);

		T&	operator[](const unsigned int idx) const;
		unsigned int	size() const;
};

template <typename T>
Array<T>::Array() : _size(0)
{
	_arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array& obj) : _size(obj._size)
{
	_arr = new T[obj._size];
	for (unsigned int i = 0; i < obj._size; i++)
		_arr[i] = obj._arr[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& obj)
{
	if (this == &obj)
		return (*this);
	else
	{
		delete[] _arr;
		_arr = new T[obj._size];
		_size = obj._size;

		for (unsigned int i = 0; i < obj._size; i++)
			_arr[i] = obj._arr[i];
		return (*this);
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
T&	Array<T>::operator[](const unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Out of bound");
	return (_arr[i]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

#endif
