/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:22:20 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/05 20:22:58 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) : _argc(argc), _argv(argv) {}

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

unsigned int	PmergeMe::JacobsthalNumber(unsigned int idx)
{
	if (idx == 0)
		return (0);
	if (idx == 1)
		return (1);

	int	sign = idx % 2 ? -1 : 1;
	return (2 * JacobsthalNumber(idx - 1) + sign);
}

void	PmergeMe::binarySearchInsertList(std::list<int>& mainchain, std::list<int>::iterator left, std::list<int>::iterator right, int target)
{
	std::list<int>::iterator	mid = left;
	std::list<int>::iterator	tmp;
	unsigned int	i = 1;

	while (1)
	{
		if (mid == right)
			break;
		i++;
		mid++;
	}
	mid = left;
	for (unsigned int j = 0; j < (i - 1) / 2; j++)
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
				binarySearchInsertList(mainchain, left, --mid, target);
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
				mainchain.insert(tmp, target);
			else
				binarySearchInsertList(mainchain, ++mid, right, target);
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

	unsigned int	cnt = 0;
	for (unsigned int k = 1; cnt < PendingChain.size(); k++)
	{
		for (unsigned int idx = JacobsthalNumber(k); idx > JacobsthalNumber(k - 1); idx--)
		{
			if (!(idx <= PendingChain.size()))
				continue;
			std::list<int>::iterator	target = PendingChain.begin();
			std::list<int>::iterator right = MainChain.begin();
			for (unsigned int t = 0; t < MainChain.size() - 1; t++)
				right++;
			for (unsigned int j = 1; j < idx; j++)
				target++;
			binarySearchInsertList(MainChain, MainChain.begin(), right, *target);
			cnt++;
		}
	}
	std::cout << "After:    ";
	for(std::list<int>::iterator i = MainChain.begin(); i != MainChain.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

void	PmergeMe::binarySearchInsertdeque(std::deque<int>& mainchain, unsigned int left, unsigned int right, int target)
{
	unsigned int	mid = (left + right) / 2;

	if (target == mainchain[mid])
		mainchain.insert(mainchain.begin() + mid, target);
	else if (target < mainchain[mid])
	{
		if (mid == 0)
			mainchain.push_front(target);
		else
		{
			if (mainchain[mid - 1] <= target)
				mainchain.insert(mainchain.begin()+ mid, target);
			else
				binarySearchInsertdeque(mainchain, left, --mid, target);
		}
	}
	else
	{
		if (mid == mainchain.size() - 1)
			mainchain.insert(mainchain.end(), target);
		else
		{
			if (mainchain[++mid] >= target)
				mainchain.insert(mainchain.begin() + mid, target);
			else
				binarySearchInsertdeque(mainchain, mid, right, target);
		}
	}
}

void	PmergeMe::binaryInsertDeque()
{
	std::deque<int>	MainChain;
	std::deque<int>	PendingChain;

	for (unsigned int i = 0; i < _deque.size(); i++)
	{
		if (_deque[i].at(0) > 0)
			MainChain.push_back(_deque[i].at(0));
		PendingChain.push_back(_deque[i].at(1));
	}

	unsigned int	cnt = 0;
	for (unsigned int k = 1; cnt < PendingChain.size(); k++)
	{
		for (unsigned int idx = JacobsthalNumber(k); idx > JacobsthalNumber(k - 1); idx--)
		{
			if (!(idx <= PendingChain.size()))
				continue;
			binarySearchInsertdeque(MainChain, 0, MainChain.size() - 1, PendingChain[idx - 1]);
			cnt++;
		}
	}
//	for(std::deque<int>::iterator i = MainChain.begin(); i != MainChain.end(); i++)
//		std::cout << *i << " ";
//	std::cout << std::endl;
}

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

bool	PmergeMe::already_sort(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc - 1)
	{
		if (!(std::strtod(*(argv + i), NULL) < std::strtod(*(argv + i + 1), NULL)))
			return (0);
	}
	return (1);
}

void	PmergeMe::run()
{
	clock_t	startList, endList, startDeque, endDeque;
	std::cout << "Before:   ";
	for (unsigned int i = 0; i < static_cast<unsigned int>(_argc - 1); i++)
	{
		std::cout << static_cast<int>(std::strtod(*(_argv + i + 1), NULL)) << " ";
	}
	std::cout << std::endl;
	if (already_sort(_argc, _argv))
		std::cout << "already_sort" << std::endl;
	else
	{
		startList = clock();
		setList(_argc, _argv);
		binaryInsertList();
		endList = clock();
		std::cout << "Time to process a range of  " << _argc - 1 << " elements with std::list : " << endList - startList << " ms" << std::endl;
		startDeque = clock();
		setDeque(_argc, _argv);
		binaryInsertDeque();
		endDeque = clock();
		std::cout << "Time to process a range of  " << _argc - 1 << " elements with std::deque : " << endDeque - startDeque << " ms" << std::endl;
	}
}

