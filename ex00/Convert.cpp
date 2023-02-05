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

// void	Convert::setChar() {
// 	this->_char = static_cast<char>(this->_int);
// }

Convert::Convert() {
	cout << "Default constructor" << endl;
}

Convert::Convert(string str) : _str(str) {
	cout << C_GREEN << "Parameterize constructor" << endl
		<< C_CYAN << "The entred string is : " << _str << C_RES << endl;
	this->_flag_char = true;
	this->_flag_int = true;
	this->_flag_float = true;
	this->_flag_double = true;
	this->checkStringPass(str);
}

Convert::Convert(Convert const & convert) {
	cout << "Copy constructor" << endl;
	*this = convert;
}

Convert &Convert::operator = (Convert const & convert) {
	cout << "Copy assignment operator" << endl;
	if (this != &convert) {
		this->_str = convert.getStr();
		this->_char = convert.getChar();
		this->_int = convert.getInt();
		this->_float = convert.getFloat();
		this->_double = convert.getDouble();
		this->_flag_char = convert._flag_char;
		this->_flag_int = convert._flag_int;
		this->_flag_float = convert._flag_float;
		this->_flag_double = convert._flag_double;
	}
	this->checkStringPass(this->_str);
	return *this;
}

Convert::~Convert() {
	cout << C_RED <<"Destructor" << C_RES << endl;
}

void	Convert::fillChar(string str) {
	if (str.length() == 1) {
		if (isprint(str[0])) {
			this->_char = str[0];
		}
		else {
			throw NonDisplayableException();
		}
	}
	else {
		throw ImpossibleException();
	}
}

void	Convert::fillInt(string str) {
	int		i = 0;
	int		len = str.length();
	int		sign = 1;
	int		num = 0;

	if (str[i] == '-') {
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (i < len) {
		if (isdigit(str[i]))
			num = num * 10 + (str[i] - '0');
		else
			throw ImpossibleException();
		i++;
	}
	this->_int = num * sign;
}

void	Convert::fillFloat(string str) {
	int		i = 0;
	int		len = str.length();
	int		sign = 1;
	int		num = 0;
	int		dec = 0;
	int		decLen = 0;


	if (str == "-inff" || str == "+inff" || str == "nanf" 
		|| str == "-inf" || str == "+inf" || str == "nan") {
		if (str == "-inff" || str == "-inf")
			this->_float = -1.0 / 0.0;
		else if (str == "+inff" || str == "+inf")
			this->_float = 1.0 / 0.0;
		else if (str == "nanf" || str == "nan")
			this->_float = 0.0 / 0.0;
		return ;
	}
	if (str[i] == '-') {
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (i < len) {
		if (isdigit(str[i]))
			num = num * 10 + (str[i] - '0');
		else if (str[i] == '.' || (str[i] == 'f' && i == len - 1)) {
			i++;
			while (i < len) {
				if (isdigit(str[i])) {
					dec = dec * 10 + (str[i] - '0');
					decLen++;
				}
				else
					throw ImpossibleException();
				i++;
			}
			break;
		}
		else
			throw ImpossibleException();
		i++;
	}
	this->_float = (num + (dec / pow(10, decLen))) * sign;
}

void	Convert::fillDouble(string str) {
	int		i = 0;
	int		len = str.length();
	int		sign = 1;
	int		num = 0;
	int		dec = 0;
	int		decLen = 0;

	if (str == "-inff" || str == "+inff" || str == "nanf" 
		|| str == "-inf" || str == "+inf" || str == "nan") {
		if (str == "-inff" || str == "-inf")
			this->_double = -1.0 / 0.0;
		else if (str == "+inff" || str == "+inf")
			this->_double = 1.0 / 0.0;
		else if (str == "nanf" || str == "nan")
			this->_double = 0.0 / 0.0;
		return ;
	}
	if (str[i] == '-') {
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (i < len) {
		if (isdigit(str[i]))
			num = num * 10 + (str[i] - '0');
		else if (str[i] == '.') {
			i++;
			while (i < len) {
				if (isdigit(str[i]) || (str[i] == 'f' && i == len - 1)) {
					dec = dec * 10 + (str[i] - '0');
					decLen++;
				}
				else
					throw ImpossibleException();
				i++;
			}
			break;
		}
		else
			throw ImpossibleException();
		i++;
	}
	this->_double = (num + (dec / pow(10, decLen))) * sign;
}

void	Convert::checkStringPass(string str) {

	try {
		this->fillChar(str);
	} catch (std::exception &e) {
		if (!strcmp(e.what(), "impossible"))
			this->_flag_char = 1;
		else if (!strcmp(e.what(), "non displayable"))
			this->_flag_char = 2;
	}
	try {
		this->fillInt(str);
	} catch (std::exception &e) {
		this->_flag_int = false;
	}
	try {
		this->fillFloat(str);
	} catch (std::exception &e) {
		this->_flag_float = false;
	}
	try {
		this->fillDouble(str);
	} catch (std::exception &e) {
		this->_flag_double = false;
	}
}

void	Convert::printAll() {
	if (this->_flag_char == 1)
		cout << "char: impossible" << endl;
	else if (this->_flag_char == 2)
		cout << "char: Non displayable" << endl;
	else
		cout << "char: " << "'" << this->_char << "'" << endl;
	if (this->_flag_int)
		cout << "int: " << this->_int << endl;
	else
		cout << "int: impossible" << endl;
	if (this->_flag_float)
		cout << "float: " << this->_float << "f" << endl;
	else
		cout << "float: impossible" << endl;
	if (this->_flag_double)
		cout << "double: " << this->_double << endl;
	else
		cout << "double: impossible" << endl;
}
