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
			std::cout << "RobotomyRequestForm(" << _target << ")'s robotomized completely." << std::endl;
		else
			std::cout << "RobotomyRequestForm(" << _target << ") failed to robotomize." << std::endl;
	}
}
