/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:39:29 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 18:54:26 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUND_HPP
# define GROUND_HPP

# include "Node.hpp"

class Ground
{
	private:
		node *_head;

	public:
		Ground();
		Ground(const Ground& obj);
		~Ground();
		Ground& operator=(const Ground& obj);

		void	addNode(AMateria *data);
		void	clearGround();
};

#endif
