#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = value << _fracBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(value * (1 << _fracBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = obj.getRawBits();
	return *this;
}

const int	Fixed::_fracBits = 8;

int Fixed::getRawBits(void) const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_rawBits / (1 << _fracBits);
}

int Fixed::toInt(void) const
{
	return _rawBits >> _fracBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}

bool	Fixed::operator>(const Fixed& obj) const
{
	return (_rawBits > obj.getRawBits());
}

bool	Fixed::operator<(const Fixed& obj) const
{
	return (_rawBits < obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed& obj) const
{
	return (_rawBits >= obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed& obj) const
{
	return (_rawBits <= obj.getRawBits());
}

bool	Fixed::operator==(const Fixed& obj) const
{
	return (_rawBits == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed& obj) const
{
	return (_rawBits != obj.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& obj) const
{
	return (Fixed(toFloat() + obj.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& obj) const
{
	return (Fixed(toFloat() - obj.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& obj) const
{
	return (Fixed(toFloat() * obj.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& obj) const
{
	return (Fixed(toFloat() / obj.toFloat()));
}

Fixed&	Fixed::operator++()
{
	_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	_rawBits++;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	_rawBits--;
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}
Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}
