/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:14:15 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/03 21:40:02 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "------------------MutantStack case#1------------------" << std::endl;
	{
		MutantStack<int> mstack;
	
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack size 2 : " << mstack.size() << std::endl;
		std::cout << "mstack top 17 : " << mstack.top() << std::endl;
	
		mstack.pop();
		std::cout << "mstack size 1 : " << mstack.size() << std::endl;
		std::cout << "mstack top 5 : " << mstack.top() << std::endl;
	}
	std::cout << "\n------------------MutantStack case#2------------------" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		std::cout << "case#2.1 iterator" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << "\ncase#2.2 reverse_iterator" << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		++rit;
		--rit;
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}

		std::cout << "\ncase#2.3 const_iterator" << std::endl;
		MutantStack<int>::const_iterator cit = mstack.begin();
		MutantStack<int>::const_iterator cite = mstack.end();
		++cit;
		--cit;
		while (cit != cite)
		{
			std::cout << *cit << std::endl;
			++cit;
		}

		std::cout << "\ncase#2.4 const_reverse_iterator" << std::endl;
		MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator crite = mstack.rend();
		++crit;
		--crit;
		while (crit != crite)
		{
			std::cout << *crit << std::endl;
			++crit;
		}
	}
	std::cout << "\n------------------list case#1------------------" << std::endl;
	{
	std::list<int> mstack;
	
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "mstack size 2 : " << mstack.size() << std::endl;
		std::cout << "mstack top 17 : " << mstack.back() << std::endl;
	
		mstack.pop_back();
		std::cout << "mstack size 1 : " << mstack.size() << std::endl;
		std::cout << "mstack top 5 : " << mstack.back() << std::endl;
	}
	std::cout << "\n------------------list case#2------------------" << std::endl;
	{
		std::list<int> mstack;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::cout << "case#2.1 iterator" << std::endl;
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << "\ncase#2.2 reverse_iterator" << std::endl;
		std::list<int>::reverse_iterator rit = mstack.rbegin();
		std::list<int>::reverse_iterator rite = mstack.rend();
		++rit;
		--rit;
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}

		std::cout << "\ncase#2.3 const_iterator" << std::endl;
		std::list<int>::const_iterator cit = mstack.begin();
		std::list<int>::const_iterator cite = mstack.end();
		++cit;
		--cit;
		while (cit != cite)
		{
			std::cout << *cit << std::endl;
			++cit;
		}

		std::cout << "\ncase#2.4 const_reverse_iterator" << std::endl;
		std::list<int>::const_reverse_iterator crit = mstack.rbegin();
		std::list<int>::const_reverse_iterator crite = mstack.rend();
		++crit;
		--crit;
		while (crit != crite)
		{
			std::cout << *crit << std::endl;
			++crit;
		}
	}
	return (0);
}
