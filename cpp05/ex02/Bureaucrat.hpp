#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& obj);

		int					getGrade() const;
		const std::string&	getName() const;
		void				increaseGrade();
		void				decreaseGrade();

		void				signForm(AForm& form);
		void				executeForm(AForm const & form);

		std::runtime_error	GradeTooHighException();
		std::runtime_error	GradeTooLowException();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
