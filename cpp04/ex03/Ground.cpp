/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:39:29 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/13 18:39:45 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ground.hpp"

Ground::Ground() : _head(NULL) {}

Ground::Ground(const Ground& obj) : _head(obj._head) {}

Ground::~Ground()
{
	node*	temp = _head;
	node*	temp2;

	while (temp)
	{
		temp2 = temp->next;
		delete temp->data;
		delete temp;
		temp = temp2;
	}
}

Ground& Ground::operator=(const Ground& obj)
{
	_head = obj._head;
	return (*this);
}

void	Ground::addNode(AMateria *data)
{
	node*	temp = _head;
	node*	newNode;

	if (_head == NULL)
	{
		_head = new node;
		_head->data = data;
		_head->next = NULL;
		return;
	}

	while (temp->next)
		temp = temp->next;
	newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	temp->next = newNode;
}


void	Ground::clearGround()
{
	node*	temp = _head;
	node*	temp2;

	while (temp)
	{
		temp2 = temp->next;
		delete temp->data;
		delete temp;
		temp = temp2;
	}
}
