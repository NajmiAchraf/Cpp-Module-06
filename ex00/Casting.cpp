#include "Casting.hpp"

string	Casting::getStr() const {
	return this->_str;
}

char	Casting::getChar() const {
	return this->_char;
}

int		Casting::getInt() const {
	return this->_int;
}

float	Casting::getFloat() const {
	return this->_float;
}

double	Casting::getDouble() const {
	return this->_double;
}

int		Casting::getType() const {
	return this->_type;
}

int		Casting::getFlagChar() const {
	return this->_flag_char;
}

bool	Casting::getFlagInt() const {
	return this->_flag_int;
}

bool	Casting::getFlagFloat() const {
	return this->_flag_float;
}

bool	Casting::getFlagDouble() const {
	return this->_flag_double;
}

Casting::Casting() {
	cout << "Default constructor" << endl;
}

Casting::Casting(string str) : _str(str) {
	cout << C_GREEN << "Parameterize constructor" << endl
		<< C_CYAN << "The entred string is : " << _str << C_RES << endl;
	this->_type = -1;
	this->_flag_char = true;
	this->_flag_int = true;
	this->_flag_float = true;
	this->_flag_double = true;
	this->checkStringType(str);
}

Casting::Casting(Casting const & Casting) {
	cout << "Copy constructor" << endl;
	*this = Casting;
}

Casting &Casting::operator = (Casting const & Casting) {
	cout << "Copy assignment operator" << endl;
	if (this != &Casting) {
		this->_str = Casting.getStr();
		this->_char = Casting.getChar();
		this->_int = Casting.getInt();
		this->_float = Casting.getFloat();
		this->_double = Casting.getDouble();
		this->_flag_char = Casting._flag_char;
		this->_flag_int = Casting._flag_int;
		this->_flag_float = Casting._flag_float;
		this->_flag_double = Casting._flag_double;
	}
	this->checkStringType(this->_str);
	return *this;
}

Casting::~Casting() {
	cout << C_RED <<"Destructor" << C_RES << endl;
}

char	Casting::toChar(string str) {
	if (str.length() == 1) {
		if (isprint(this->toInt(str))) {
			return (this->toInt(str));
		}
		else {
			throw NonDisplayableException();
		}
	}
	else {
		throw ImpossibleException();
	}
}

int		Casting::toInt(string str) {
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
	return (num * sign);
}

float	Casting::toFloat(string str) {
	int		i = 0;
	int		len = str.length();
	int		sign = 1;
	int		num = 0;
	int		dec = 0;
	int		decLen = 0;


	if (str == "-inff" || str == "+inff" || str == "nanf" 
		|| str == "-inf" || str == "+inf" || str == "nan") {
		if (str == "-inff" || str == "-inf")
			return (-1.0 / 0.0);
		else if (str == "+inff" || str == "+inf")
			return (1.0 / 0.0);
		else if (str == "nanf" || str == "nan")
			return (0.0 / 0.0);
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
	return ((num + (dec / pow(10, decLen))) * sign);
}

double	Casting::toDouble(string str) {
	int		i = 0;
	int		len = str.length();
	int		sign = 1;
	int		num = 0;
	int		dec = 0;
	int		decLen = 0;

	if (str == "-inff" || str == "+inff" || str == "nanf" 
		|| str == "-inf" || str == "+inf" || str == "nan") {
		if (str == "-inff" || str == "-inf")
			return (-1.0 / 0.0);
		else if (str == "+inff" || str == "+inf")
			return (1.0 / 0.0);
		else if (str == "nanf" || str == "nan")
			return (0.0 / 0.0);
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
	return ((num + (dec / pow(10, decLen))) * sign);
}

void	Casting::fillChar(string str) {
	this->_char = this->toChar(str);
}

void	Casting::fillInt(string str) {
	this->_int = this->toInt(str);
}

void	Casting::fillFloat(string str) {
	this->_float = this->toFloat(str);
}

void	Casting::fillDouble(string str) {
	this->_double = this->toDouble(str);
}

void	Casting::castTheType() {
	if (this->_type == 0 && this->_flag_char == 0) {
		this->_int = static_cast<int>(this->_char);
		this->_float = static_cast<float>(this->_char);
		this->_double = static_cast<double>(this->_char);
	} else if (this->_type == 1 && this->_flag_int == true) {
		try {
			if (isprint(this->_int))
				this->_char = this->toInt(this->_str);
			else {
				this->_char = static_cast<char>(this->_int);
				this->_flag_char = 2;
			}
		} catch (std::exception &e) {
			this->_flag_char = 1;
		}
		this->_float = static_cast<float>(this->_int);
		this->_double = static_cast<double>(this->_int);
	} else if (this->_type == 2 && this->_flag_float == true) {
		try {
			if (isprint(this->_float))
				this->_char = static_cast<int>(this->toFloat(this->_str));
			else {
				this->_char = static_cast<char>(this->_float);
				this->_flag_char = 2;
			}
		} catch (std::exception &e) {
			this->_flag_char = 1;
		}
		this->_int = static_cast<int>(this->_float);
		this->_double = static_cast<double>(this->_float);
	} else if (this->_type == 3 && this->_flag_double == true) {
		try {
			if (isprint(this->_double))
				this->_char = static_cast<int>(this->toDouble(this->_str));
			else {
				this->_char = static_cast<char>(this->_double);
				this->_flag_char = 2;
			}
		} catch (std::exception &e) {
			this->_flag_char = 1;
		}
		this->_int = static_cast<int>(this->_double);
		this->_float = static_cast<float>(this->_double);
	}
}

void	Casting::fillTheType(string str) {
	if (this->_type == 0) {
		try {
			this->fillChar(str);
		} catch (std::exception &e) {
			if (!strcmp(e.what(), "impossible"))
				this->_flag_char = 1;
			else if (!strcmp(e.what(), "non displayable"))
				this->_flag_char = 2;
		}
	} else if (this->_type == 1) {
		try {
			this->fillInt(str);
		} catch (std::exception &e) {
			if (!strcmp(e.what(), "impossible"))
				this->_flag_int = false;
		}
	} else if (this->_type == 2) {
		try {
			this->fillFloat(str);
		} catch (std::exception &e) {
			if (!strcmp(e.what(), "impossible"))
				this->_flag_float = false;
		}
	} else if (this->_type == 3) {
		try {
			this->fillDouble(str);
		} catch (std::exception &e) {
			if (!strcmp(e.what(), "impossible"))
				this->_flag_double = false;
		}
	} else if (this->_type == -1) {
		this->_flag_char = 1;
		this->_flag_int = false;
		this->_flag_float = false;
		this->_flag_double = false;
	}
	this->castTheType();
}

void	Casting::checkStringType(string str) {
	if (str.length() == 1 && isascii(this->toInt(str)))
		this->_type = 0;
	else if ((str.find('.') != string::npos && str.find('f') != string::npos)
				|| (str == "nanf" || str == "-inff" || str == "+inff"))
		this->_type = 2;
	else if (str.find('.') != string::npos || (str == "nan" || str == "-inf" || str == "+inf"))
		this->_type = 3;
	else {
		this->_type = 1;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!isdigit(str[i]))
				this->_type = -1;
		}
	}
	this->fillTheType(str);
}

std::ostream &operator << (std::ostream &out, Casting const &cast) {
	if (cast.getFlagChar() == 1)
		out << "char: impossible" << endl;
	else if (cast.getFlagChar() == 2)
		out << "char: Non displayable" << endl;
	else
		out << "char: " << "'" << cast.getChar() << "'" << endl;

	if (cast.getFlagInt())
		out << "int: " << cast.getInt() << endl;
	else
		out << "int: impossible" << endl;

	if (cast.getFlagFloat())
		out << "float: " << cast.getFloat() << "f" << endl;
	else
		out << "float: impossible" << endl;

	if (cast.getFlagDouble())
		out << "double: " << cast.getDouble() << endl;
	else
		out << "double: impossible" << endl;
	return out;
}
