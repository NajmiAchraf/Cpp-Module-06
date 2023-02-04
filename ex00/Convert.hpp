#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <exception>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Convert {

private:

	string	_str;
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

	void	setStr(string str);
	void	setChar();
	void	setInt();
	void	setFloat();
	void	setDouble();

	Convert();
	Convert(string str);
	Convert(Convert const & convert);
	Convert &operator = (Convert const & convert);
	~Convert();

	void	convertToChar();
	void	convertToInt();
	void	convertToFloat();
	void	convertToDouble();

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