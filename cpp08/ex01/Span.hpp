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
