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

		bool	operator>(const Fixed& obj) const;
		bool	operator<(const Fixed& obj) const;
		bool	operator>=(const Fixed& obj) const;
		bool	operator<=(const Fixed& obj) const;
		bool	operator==(const Fixed& obj) const;
		bool	operator!=(const Fixed& obj) const;

		Fixed	operator+(const Fixed& obj) const;
		Fixed	operator-(const Fixed& obj) const;
		Fixed	operator*(const Fixed& obj) const;
		Fixed	operator/(const Fixed& obj) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& obj);

#endif
