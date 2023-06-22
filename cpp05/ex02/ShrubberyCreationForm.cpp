/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:29:56 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/22 16:30:00 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	: AForm(obj), _target(obj._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
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

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (!getStatus())
		throw AForm::IsNotSignedException();
	else if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream outfile(_target + "_shrubbery");
 		outfile << "             * *    " << std::endl;
 		outfile << "          *    *  *" << std::endl;
 		outfile << "     *  *    *     *  *" << std::endl;
 		outfile << "    *     *    *  *    *" << std::endl;
 		outfile << "* *   *    *    *    *   *" << std::endl;
 		outfile << "*     *  *    * * .#  *   *" << std::endl;
 		outfile << "*   *     * #.  .# *   *" << std::endl;
 		outfile << " *     '#.  #: #' * *    *" << std::endl;
 		outfile << "*   * * '#. ##'       *" << std::endl;
 		outfile << "  *       '###" << std::endl;
 		outfile << "            '##" << std::endl;
 		outfile << "             ##." << std::endl;
 		outfile << "             .##:" << std::endl;
 		outfile << "             :###" << std::endl;
 		outfile << "             ;###" << std::endl;
 		outfile << "           ,####." << std::endl;
		outfile.close();
	}
}

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& obj)
{
	os << "The form(" << obj.getName() << ") : signStatus(" 
		<< obj.getStatus() << "), signGrade(" 
		<< obj.getSignGrade() << "), executeGrade(" 
		<< obj.getExecuteGrade() << "), target("
		<< obj.getTarget() <<")";
	return (os);
}
