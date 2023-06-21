#include "Form.hpp"

Form::Form() : _name("Default"), _signStatus(0), _signGrade(150), _executeGrade(150) {}

Form::Form(const std::string name, int signGrade, int executeGrade) : _name(name), _signStatus(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& obj) : _name(obj._name), _signStatus(obj._signStatus), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade) {}

Form::~Form() {}

Form& Form::operator=(const Form& obj)
{
	if (this == &obj)
		return (*this);
	else
		_signStatus = obj._signStatus;
	return (*this);
}

const std::string&	Form::getName() const
{
	return (_name);
}

bool	Form::getStatus() const
{
	return (_signStatus);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecuteGrade() const
{
	return (_executeGrade);
}

void	Form::beSigned(const Bureaucrat& user)
{
	if (user.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else
		_signStatus = 1;
}

std::runtime_error	Form::GradeTooHighException() const
{
	return (std::runtime_error("grade is too high"));
}
std::runtime_error	Form::GradeTooLowException() const
{
	return (std::runtime_error("grade is too low"));
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << "The form(" << obj.getName() << ") : signStatus(" 
		<< obj.getStatus() << "), signGrade(" 
		<< obj.getSignGrade() << "), executeGrade(" 
		<< obj.getExecuteGrade() << ")";
	return (os);
}
