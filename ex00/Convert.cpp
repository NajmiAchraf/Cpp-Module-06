#include "Convert.hpp"

string	Convert::getStr() const {
	return this->_str;
}

char	Convert::getChar() const {
	return this->_char;
}

int		Convert::getInt() const {
	return this->_int;
}

float	Convert::getFloat() const {
	return this->_float;
}

double	Convert::getDouble() const {
	return this->_double;
}

void	Convert::setStr(string str) {
	this->_str = str;
}

void	Convert::setChar() {
	this->_char = static_cast<char>(this->_int);
}

Convert::Convert() {
	cout << "Default constructor" << endl;
}

Convert::Convert(string str) : _str(str) {
	cout << "Parametric constructor" << endl;
}

Convert::Convert(Convert const & convert) {
	cout << "Copy constructor" << endl;
	*this = convert;
}

Convert &Convert::operator = (Convert const & convert) {
	cout << "Assignation operator" << endl;
	if (this != &convert) {
		this->_str = convert.getStr();
		this->_char = convert.getChar();
		this->_int = convert.getInt();
		this->_float = convert.getFloat();
		this->_double = convert.getDouble();
	}
	return *this;
}

Convert::~Convert() {
	cout << "Destructor" << endl;
}

