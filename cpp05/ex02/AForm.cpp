/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:29:32 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/22 16:30:00 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signStatus(0), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const std::string name, int signGrade, int executeGrade) 
	: _name(name), _signStatus(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& obj) 
	: _name(obj._name), _signStatus(obj._signStatus), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& obj)
{
	if (this == &obj)
		return (*this);
	else
		_signStatus = obj._signStatus;
	return (*this);
}

const std::string&	AForm::getName() const
{
	return (_name);
}

bool	AForm::getStatus() const
{
	return (_signStatus);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

void	AForm::beSigned(const Bureaucrat& user)
{
	if (user.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	else
		_signStatus = 1;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char *AForm::IsNotSignedException::what() const throw()
{
	return ("form is not signed");
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os << "The form(" << obj.getName() << ") : signStatus(" 
		<< obj.getStatus() << "), signGrade(" 
		<< obj.getSignGrade() << "), executeGrade(" 
		<< obj.getExecuteGrade() << ")";
	return (os);
}
