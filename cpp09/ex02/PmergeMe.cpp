/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:22:20 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/04 20:10:47 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
{
	setList(argc, argv);
	setDeque(argc, argv);
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	_list = obj._list;
	_deque = obj._deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (this == &obj)
		return (*this);

	_list = obj._list;
	_deque = obj._deque;
	return (*this);
}

void	binarySearchInsert(std::list<int>& mainchain, std::list<int>::iterator left, std::list<int>::iterator right, int target)
{
	std::list<int>::iterator	mid = left;
	std::list<int>::iterator	tmp;

	int	i = 1;

	while (1)
	{
		if (mid == right)
			break;
		i++;
		mid++;
	}
	mid = left;
	for (int j = 0; j < i / 2; j++)
		mid++;
	if (target == *mid)
		mainchain.insert(mid, target);
	else if (target < *mid)
	{
		if (mid == mainchain.begin())
			mainchain.push_front(target);
		else
		{
			tmp = mid;
			if (*(--tmp) <= target)
				mainchain.insert(mid, target);
			else
				binarySearchInsert(mainchain, left, mid--, target);
		}
	}
	else
	{
		tmp = mid;
		if ((++tmp) == mainchain.end())
			mainchain.push_back(target);
		else
		{
			if (*tmp >= target)
				mainchain.insert(mid, target);
			else
				binarySearchInsert(mainchain, mid++, right, target);
		}
	}
}

void	PmergeMe::binaryInsertList()
{
	std::list<int>	MainChain;
	std::list<int>	PendingChain;

	for (std::list<std::vector<int> >::iterator i = _list.begin(); i != _list.end(); i++)
	{
		if (i->at(0) > 0)
			MainChain.push_back(i->at(0));
		PendingChain.push_back(i->at(1));
	}
	for(std::list<int>::iterator i = MainChain.begin(); i != MainChain.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	for(std::list<int>::iterator i = PendingChain.begin(); i != PendingChain.end(); i++)
		std::cout << *i << " ";

	
}

void	PmergeMe::binaryInsertDeque()
{}

void	PmergeMe::setList(int argc, char **argv)
{
	int	a;
	int	b;
	int	i;
	if (argc % 2)
	{
		for (i = 1; i < argc; i += 2)
		{
			std::vector<int> temp;
			a = static_cast<int>(std::strtod(argv[i], NULL));
			b = static_cast<int>(std::strtod(argv[i + 1], NULL));
			if (a > b)
			{
				temp.push_back(a);
				temp.push_back(b);
			}
			else
			{
				temp.push_back(b);
				temp.push_back(a);
			}
			std::cout << "push_back(temp) : " << temp.at(0) << " " << temp.at(1) << std::endl;
			_list.push_back(temp);
			temp.clear();
		}
		_list.sort();
	}
	else
	{
		for (i = 1; i < argc - 1; i += 2)
		{
			std::vector<int> temp;
			a = static_cast<int>(std::strtod(argv[i], NULL));
			b = static_cast<int>(std::strtod(argv[i + 1], NULL));
			if (a > b)
			{
				temp.push_back(a);
				temp.push_back(b);
			}
			else
			{
				temp.push_back(b);
				temp.push_back(a);
			}
			std::cout << "push_back(temp) : " << temp.at(0) << " " << temp.at(1) << std::endl;
			_list.push_back(temp);
			temp.clear();
		}
		_list.sort();
		std::vector<int> temp;
		temp.push_back(-1);
		temp.push_back(static_cast<int>(std::strtod(argv[i], NULL)));
		_list.push_back(temp);
	}
}

void	PmergeMe::setDeque(int argc, char **argv)
{
	int	a;
	int	b;
	int	i;
	if (argc % 2)
	{
		for (i = 1; i < argc; i += 2)
		{
			std::vector<int> temp;
			a = static_cast<int>(std::strtod(argv[i], NULL));
			b = static_cast<int>(std::strtod(argv[i + 1], NULL));
			if (a > b)
			{
				temp.push_back(a);
				temp.push_back(b);
			}
			else
			{
				temp.push_back(b);
				temp.push_back(a);
			}
			std::cout << "push_back(temp) : " << temp.at(0) << " " << temp.at(1) << std::endl;
			_deque.push_back(temp);
			temp.clear();
		}
		std::sort(_deque.begin(), _deque.end());
	}
	else
	{
		for (i = 1; i < argc - 1; i += 2)
		{
			std::vector<int> temp;
			a = static_cast<int>(std::strtod(argv[i], NULL));
			b = static_cast<int>(std::strtod(argv[i + 1], NULL));
			if (a > b)
			{
				temp.push_back(a);
				temp.push_back(b);
			}
			else
			{
				temp.push_back(b);
				temp.push_back(a);
			}
			std::cout << "push_back(temp) : " << temp.at(0) << " " << temp.at(1) << std::endl;
			_deque.push_back(temp);
			temp.clear();
		}
		std::sort(_deque.begin(), _deque.end());
		std::vector<int> temp;
		temp.push_back(-1);
		temp.push_back(static_cast<int>(std::strtod(argv[i], NULL)));
		_deque.push_back(temp);
	}
}

void	PmergeMe::run()
{
	binaryInsertList();
}
