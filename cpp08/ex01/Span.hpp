/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:14:39 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/03 21:14:43 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
	private:
		std::vector<int>	_data;
		unsigned int		_N;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& obj);
		~Span();

		Span& operator=(const Span& obj);

		void	addNumber(int n);
		void	addNumber_range(int min, int max);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

	
		class FullDataSpanException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class LessThanTwoException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
