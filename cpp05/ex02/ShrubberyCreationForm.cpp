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
	}
}
