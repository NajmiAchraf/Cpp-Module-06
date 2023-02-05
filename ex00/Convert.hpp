#ifndef CONVERT_HPP
#define CONVERT_HPP

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

class Convert {

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

	void	setStr(string str);
	// void	setChar();
	// void	setInt();
	// void	setFloat();
	// void	setDouble();

	Convert();
	Convert(string str);
	Convert(Convert const & convert);
	Convert &operator = (Convert const & convert);
	~Convert();

	void	fillChar(string str);
	void	fillInt(string str);
	void	fillFloat(string str);
	void	fillDouble(string str);

	// void	convertToChar();
	// void	convertToInt();
	// void	convertToFloat();
	// void	convertToDouble();

	void	checkStringPass(string str);
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

#endif