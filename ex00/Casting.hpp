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
	char	_char;
	int		_int;
	float	_float;
	double	_double;

	int		_type; // 0 = char, 1 = int, 2 = float, 3 = double
	int		_flag_char;
	bool	_flag_int;
	bool	_flag_float;
	bool	_flag_double;

public:

	string	getStr() const;
	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;

	int		getType() const;
	int		getFlagChar() const;
	bool	getFlagInt() const;
	bool	getFlagFloat() const;
	bool	getFlagDouble() const;

	Casting();
	Casting(string str);
	Casting(Casting const & casting);
	Casting &operator = (Casting const & casting);
	~Casting();

	char	toChar(string str);
	int		toInt(string str);
	float	toFloat(string str);
	double	toDouble(string str);

	void	fillChar(string str);
	void	fillInt(string str);
	void	fillFloat(string str);
	void	fillDouble(string str);

	void	fillTheType(string str);
	void	castTheType();
	void	checkStringType(string str);
	void	printAll();

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