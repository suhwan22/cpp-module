/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 05:10:38 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/29 05:28:02 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value; mirror[i] = value;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "numbers[" << i << "]: " << numbers[i] << std::endl;
        std::cout << "mirror[" << i << "]: " << mirror[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try
    {
        std::cout << "\n------------------------------------------------------------" << std::endl;
        Array<int> tmp = numbers;
        tmp[3] = -123131;
        std::cout << "origin numbers[3]:" << numbers[3] << std::endl;
        std::cout << "tmp[3]:" << tmp[3] << std::endl;

        Array<int> test(tmp);
        test[3] = 99885;
        std::cout << "tmp[3]:" << tmp[3] << std::endl;
        std::cout << "test[3]:" << test[3] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n----------------------out of bound case-----------------------------" << std::endl;
    try
    {
        std::cout << "try numbers[-2]: ";
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "try numbers[MAX_VAL]: ";
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;
    return 0;
}
