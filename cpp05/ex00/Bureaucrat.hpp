#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

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

		std::runtime_error	GradeTooHighException();
		std::runtime_error	GradeTooLowException();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
