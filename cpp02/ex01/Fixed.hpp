/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:05:37 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/10 19:09:55 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
	private:
		int	_rawBits;
		static const int	_fracBits;

	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		Fixed& operator=(const Fixed& obj);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		float toFloat(void) const;
		int	toInt(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& obj);

#endif
