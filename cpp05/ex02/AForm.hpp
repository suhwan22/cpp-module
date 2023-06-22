/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:29:33 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/22 16:30:00 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};

		class IsNotSignedException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif
