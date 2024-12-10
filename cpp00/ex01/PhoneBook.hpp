/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:37:05 by suhkim            #+#    #+#             */
/*   Updated: 2023/02/25 08:34:37 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		number_of_contact;
	public:
		PhoneBook();
		~PhoneBook();

		std::string	set_ten(std::string str) const;
		void	print_err_input() const;
		void	add_contact();
		void	search_contact();
		void	show_sum_info() const;
		void	show_detail_info(int idx) const;
		int		find_oldest_contact() const;

		int		ft_getline(std::string str, std::string& target);
		int		get_num() const;
		void	add_number_of_contact();
};

#endif
