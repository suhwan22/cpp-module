/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:48:30 by suhkim            #+#    #+#             */
/*   Updated: 2023/06/22 15:48:33 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif
