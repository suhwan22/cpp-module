/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:22:20 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/05 20:20:37 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>

typedef std::list<std::vector<int> > List_v;
typedef std::deque<std::vector<int> > Deque_v;

class PmergeMe
{
	private:
		int	_argc;
		char **_argv;
		PmergeMe();


		std::list< std::vector<int> >	_list;
		std::deque< std::vector<int> >	_deque;
		unsigned int	JacobsthalNumber(unsigned int idx);
		void	setList(int argc, char **argv);
		void	setDeque(int argc, char **argv);
		void	binaryInsertList();
		void	binarySearchInsertList(std::list<int>& mainchain, std::list<int>::iterator left, std::list<int>::iterator right, int target);
		void	binaryInsertDeque();
		void	binarySearchInsertdeque(std::deque<int>& mainchain, unsigned int left, unsigned int right, int target);
		bool	already_sort(int argc, char **argv);
		std::list<std::vector<int> > mergeSortList(std::list<std::vector<int> >& lst);
		std::list<std::vector<int> > mergeList(std::list<std::vector<int> >& left, std::list<std::vector<int> >& right);
	public:
//-----------------------private---------------------------
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		void	run();
};

#endif
