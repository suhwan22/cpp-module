#ifndef FT_HPP
#define FT_HPP

#include <iostream>
#include <limits>
#include <iomanip>

typedef enum e_Type
{
	Invalid,
	Char,
	Double,
	Int,
	Float,
}	Type;

bool	isChar(std::string input);
bool	isDouble(std::string input);
bool	isInt(std::string input);
bool	isFloat(std::string input);

Type	detectType(std::string input);

void	doProcess(Type _type, std::string input);


#endif
