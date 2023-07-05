/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:22:20 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/04 19:41:19 by suhkim           ###   ########.fr       */
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
		PmergeMe();

	public:

		std::list< std::vector<int> >	_list;
		std::deque< std::vector<int> >	_deque;
		void	setList(int argc, char **argv);
		void	setDeque(int argc, char **argv);
		void	binaryInsertList();
		void	binaryInsertDeque();

//-----------------------private---------------------------
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		void	run();
		void	sortList();
		void	sortDeque();
};

#endif
