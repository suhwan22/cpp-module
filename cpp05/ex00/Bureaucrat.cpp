/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:18:30 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/22 15:18:36 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}
		
Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this == &obj)
		return (*this);
	else
		_grade = obj._grade;
	return (*this);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string&	Bureaucrat::getName() const
{
	return (_name);
}

void	Bureaucrat::increaseGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade -= 1;
}

void	Bureaucrat::decreaseGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too Low");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}
