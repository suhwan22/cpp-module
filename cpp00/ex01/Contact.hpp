/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:07:01 by suhkim            #+#    #+#             */
/*   Updated: 2023/02/25 08:45:09 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include  <string>

class Contact
{
	private:
		int			each_idx;
		std::string first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	dark_secret;
	public:
		Contact();
		~Contact();

		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phone_number() const;
		std::string get_dark_secret() const;
		int	get_this_idx() const;

		void	set_first_name(const std::string name);
		void	set_last_name(const std::string name);
		void	set_nickname(const std::string name);
		void	set_phone_number(const std::string nums);
		void	set_dark_secret(const std::string secret);
		void	set_this_idx(const int idx);
};

#endif
