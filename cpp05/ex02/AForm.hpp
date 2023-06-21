#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_signStatus;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		AForm();
		AForm(const std::string name, int signGrade, int executeGrade);
		AForm(const AForm& obj);
		virtual ~AForm();
		AForm& operator=(const AForm& obj);

		const std::string&	getName() const;
		bool				getStatus() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void				beSigned(const Bureaucrat& user);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		std::runtime_error	GradeTooHighException() const;
		std::runtime_error	GradeTooLowException() const;
		std::runtime_error	IsNotSignedException() const;
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif
