/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:14:39 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/03 21:14:43 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _N(N)
{
	_data.reserve(N);
}

Span::Span(const Span& obj) : _data(obj._data), _N(obj._N) {}

Span::~Span() {}

Span&	Span::operator=(const Span& obj)
{
	if (this == &obj)
		return (*this);
	else
	{
		_N = obj._N;
		_data = obj._data;
		return (*this);
	}
}

void	Span::addNumber(int n)
{
	if (_data.size() >= _N)
		throw FullDataSpanException();
	else
		_data.push_back(n);
}

void	Span::addNumber_range(int min, int max)
{
	if (_data.size() + max - min + 1 > _N)
		throw FullDataSpanException();
	else if (max < min)
		throw std::out_of_range("max value < min value Exception");

	for (int value = min; value <= max; value++)
		_data.push_back(value);
}

unsigned int	Span::shortestSpan()
{
	if (_data.size() < 2)
		throw LessThanTwoException();

	std::vector<int>	temp = _data;
	unsigned int		shortest;

	std::sort(temp.begin(), temp.end());
	shortest = temp[1] - temp[0];
	for (std::vector<int>::iterator i = temp.begin(); i < temp.end() - 1; i++)
		if (static_cast<unsigned int>(*(i + 1) - *i) < shortest)
			shortest = *(i + 1) - *i;
	return (shortest);
}

unsigned int	Span::longestSpan()
{
	if (_data.size() < 2)
		throw LessThanTwoException();

	return (*std::max_element(_data.begin(), _data.end()) - *std::min_element(_data.begin(), _data.end()));
}

const char*	Span::FullDataSpanException::what() const throw()
{
	return ("It's already too much to fill");
}

const char* Span::LessThanTwoException::what() const throw()
{
	return ("It has less than two data");
}
