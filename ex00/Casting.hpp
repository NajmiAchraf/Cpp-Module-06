#ifndef CASTING_HPP
#define CASTING_HPP

#include <iostream>
#include <exception>
#include <cstring>
#include <math.h>

using std::cout;
using std::endl;
using std::string;

#define C_RES	"\033[0m"
#define C_RED	"\033[1;31m"
#define C_GREEN	"\033[1;32m"
#define C_CYAN	"\033[1;36m"

class Casting {

private:

	string	_str;
	int		_type;
	bool	_flag;
	char	_char;
	int		_int;
	float	_float;
	double	_double;

public:

	string	getStr() const;
	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;

	Casting();
	Casting(string str);
	Casting(Casting const & casting);
	Casting &operator = (Casting const & casting);
	~Casting();

	char	StringToChar();
	int		StringToInt();
	float	StringToFloat();
	double	StringToDouble();

	bool	checkInfNan() const;
	float	floatInfNan();
	double	doubleInfNan();

	char	getChar();
	int		getInt();
	float	getFloat();
	double	getDouble();

	int		checkType();
	void	fillType();

	class ImpossibleException : public std::exception {
		virtual const char* what() const throw() {
			return "impossible";
		}
	};

	class NonDisplayableException : public std::exception {
		virtual const char* what() const throw() {
			return "non displayable";
		}
	};

};

std::ostream &operator << (std::ostream &out, Casting const &cast);

#endif
