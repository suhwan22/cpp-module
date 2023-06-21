#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signStatus;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		Form();
		Form(const std::string name, int signGrade, int executeGrade);
		Form(const Form& obj);
		~Form();
		Form& operator=(const Form& obj);

		const std::string&	getName() const;
		bool				getStatus() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void				beSigned(const Bureaucrat& user);

		std::runtime_error	GradeTooHighException() const;
		std::runtime_error	GradeTooLowException() const;
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif
