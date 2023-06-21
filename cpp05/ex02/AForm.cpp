#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signStatus(0), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const std::string name, int signGrade, int executeGrade) : _name(name), _signStatus(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& obj) : _name(obj._name), _signStatus(obj._signStatus), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade) {}

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

std::runtime_error	AForm::GradeTooHighException() const
{
	return (std::runtime_error("grade is too high"));
}
std::runtime_error	AForm::GradeTooLowException() const
{
	return (std::runtime_error("grade is too low"));
}

std::runtime_error	AForm::IsNotSignedException() const
{
	return (std::runtime_error("form is not signed"));
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os << "The form(" << obj.getName() << ") : signStatus(" 
		<< obj.getStatus() << "), signGrade(" 
		<< obj.getSignGrade() << "), executeGrade(" 
		<< obj.getExecuteGrade() << ")";
	return (os);
}
