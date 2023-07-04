/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:18:00 by suhkim            #+#    #+#             */
/*   Updated: 2023/07/04 12:15:29 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	public:
		RPN();
		RPN(const RPN& obj);
		~RPN();
		RPN&	operator=(const RPN& obj);

		bool	isOperator(char c);
		void	runProcess(std::string input);
		int		calculate(std::string& input);
};

#endif
