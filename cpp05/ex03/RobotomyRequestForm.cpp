/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:31:20 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/22 16:31:23 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: AForm(obj), _target(obj._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this == &obj)
		return (*this);
	else
	{
		AForm::operator=(obj);
		_target = obj._target;
	}
	return (*this);
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
	if (!getStatus())
		throw AForm::IsNotSignedException();
	else if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Driiiilllliiinnngg!..." << std::endl;
		srand(time(NULL));
		if (rand() % 2)
			std::cout << "RobotomyRequestForm(" << _target << ") has been robotomized completely." << std::endl;
		else
			std::cout << "RobotomyRequestForm(" << _target << ") failed to robotomize." << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& obj)
{
	os << "The form(" << obj.getName() << ") : signStatus(" 
		<< obj.getStatus() << "), signGrade(" 
		<< obj.getSignGrade() << "), executeGrade(" 
		<< obj.getExecuteGrade() << "), target("
		<< obj.getTarget() <<")";
	return (os);
}
