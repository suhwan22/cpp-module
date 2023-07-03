/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:14:40 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/04 04:20:13 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "------------------case#0------------------" << std::endl;
	try
	{
		Span sp(5);
	
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "------------------case#1------------------" << std::endl;
	try
	{
		Span sp(5);
	
		sp.addNumber(-2147483648);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(2147483647);
	
		std::cout << "valid answer to shortest is 9 - 3 = 6 : " << sp.shortestSpan() << std::endl;
		std::cout << "valid answer to longest is 2147483647 - -2147483648 = 4294967295 : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n------------------case#2------------------" << std::endl;
	try
	{
		Span large_span(10000);
		for(int i = 0; i < 10000; i ++)
			large_span.addNumber(i);

		std::cout << "valid answer to shortest is 2 - 1 = 1 : " << large_span.shortestSpan() << std::endl;
		std::cout << "valid answer to longest is 9999 - 0 = 9999 : " << large_span.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n------------------case#3------------------" << std::endl;
	try
	{
		Span one_span(1);
		one_span.addNumber(1);

		std::cout << one_span.shortestSpan() << "In this case, an error must be thrown. if you see this sentence you must question" << std::endl;
		std::cout << one_span.longestSpan() << "In this case, an error must be thrown. if you see this sentence you must question" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n------------------case#3.1------------------" << std::endl;
	try
	{
		Span empty_span;

		std::cout << empty_span.shortestSpan() << "In this case, an error must be thrown. if you see this sentence you must question" << std::endl;
		std::cout << empty_span.longestSpan() << "In this case, an error must be thrown. if you see this sentence you must question" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n------------------case#4------------------" << std::endl;
	try
	{
		Span full_span(3);

		full_span.addNumber(1);
		full_span.addNumber(2);
		full_span.addNumber(3);
		full_span.addNumber(4);
		std::cout << "In this case, an error must be thrown. if you see this sentence you must question" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n------------------case#5------------------" << std::endl;
	try
	{
		Span bigger_span(20000);

		bigger_span.addNumber_range(-10000, 10000);
		std::cout << "In this case, an error must be thrown. if you see this sentence you must question" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n------------------case#6------------------" << std::endl;
	try
	{
		Span bigger_span(20000);

		bigger_span.addNumber_range(-10000, 9999);

		std::cout << "valid answer to shortest is -10000 - -9999 = 1 : " << bigger_span.shortestSpan() << std::endl;
		std::cout << "valid answer to longest is 9999 - -10000 = 19999 : " << bigger_span.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
