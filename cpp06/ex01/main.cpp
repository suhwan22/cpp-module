/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:42:31 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/28 18:53:47 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	{
		std::cout << "------------------input: Hello, Wordl!-------------------" << std::endl;
		Data		origin;
		Data		*alter;
		uintptr_t	ptr;
	
		origin.data = "Hello, World!";
		std::cout << "origin: " << origin.data << std::endl;
	
		ptr = Serializer::serialize(&origin);
		std::cout << "ptr: " << ptr << std::endl;
	
		alter = Serializer::deserialize(ptr);
		std::cout << "alter: " << alter->data << std::endl;
	}
	{
		std::cout << "------------------input: I'm suhkim-------------------" << std::endl;
		Data		origin;
		Data		*alter;
		uintptr_t	ptr;
		origin.data = "I'm suhkim";
		std::cout << "origin: " << origin.data << std::endl;
	
		ptr = Serializer::serialize(&origin);
		std::cout << "ptr: " << ptr << std::endl;
	
		alter = Serializer::deserialize(ptr);
		std::cout << "alter: " << alter->data << std::endl;
	}
	return (0);
}
