#include "Casting.hpp"

string	Casting::getStr() const {
	return this->_str;
}

Casting::Casting() {
	cout << "Default constructor" << endl;
}

Casting::Casting(string str) : _str(str) {
	cout << C_GREEN << "Parameterize constructor" << endl
		<< C_CYAN << "The entred string is : " << _str << C_RES << endl;
}

Casting::Casting(Casting const & Casting) {
	cout << "Copy constructor" << endl;
	*this = Casting;
}

Casting &Casting::operator = (Casting const & Casting) {
	cout << "Copy assignment operator" << endl;
	if (this != &Casting) {
		this->_str = Casting.getStr();
	}
	return *this;
}

Casting::~Casting() {
	cout << C_RED <<"Destructor" << C_RES << endl;
}

int		Casting::StringToInt() const {
	int		i = 0;
	int		len = this->_str.length();
	int		sign = 1;
	int		num = 0;

	if (this->_str[i] == '-') {
		sign = -1;
		i++;
	}
	else if (this->_str[i] == '+')
		i++;
	if (this->_str[i] == '\0')
		throw Casting::ImpossibleException();
	while (i < len) {
		if (isdigit(this->_str[i]))
			num = num * 10 + (this->_str[i] - '0');
		else if (this->_str[i] == '.' && this->_str[len - 1] == 'f') {
			for (i++ ; i < len - 1; i++) {
				if (!isdigit(this->_str[i]))
					throw ImpossibleException();
			}
			break;
		} else if (this->_str[i] == '.') {
			for (i++ ; i < len; i++) {
				if (!isdigit(this->_str[i]))
					throw ImpossibleException();
			}
			break;
		} else
			throw ImpossibleException();
		i++;
	}
	return (num * sign);
}

float	Casting::StringToFloat() const {
	int		i = 0;
	int		len = this->_str.length();
	int		sign = 1;
	int		num = 0;
	int		dec = 0;
	int		decLen = 0;


	if (this->_str == "-inff" || this->_str == "+inff" || this->_str == "nanf" 
		|| this->_str == "-inf" || this->_str == "+inf" || this->_str == "nan") {
		if (this->_str == "-inff" || this->_str == "-inf")
			return (-1.0 / 0.0);
		else if (this->_str == "+inff" || this->_str == "+inf")
			return (1.0 / 0.0);
		else if (this->_str == "nanf" || this->_str == "nan")
			return (0.0 / 0.0);
	}
	if (this->_str[i] == '-') {
		sign = -1;
		i++;
	}
	else if (this->_str[i] == '+')
		i++;
	if (this->_str[i] == '\0')
		throw Casting::ImpossibleException();
	while (i < len) {
		if (isdigit(this->_str[i]))
			num = num * 10 + (this->_str[i] - '0');
		else if (this->_str[i] == '.') {
			i++;
			while (i < len) {
				if (isdigit(this->_str[i])) {
					dec = dec * 10 + (this->_str[i] - '0');
					decLen++;
				} else if (this->_str[i] == 'f' && i == len - 1)
					break;
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

double	Casting::StringToDouble() const {
	int		i = 0;
	int		len = this->_str.length();
	int		sign = 1;
	int		num = 0;
	int		dec = 0;
	int		decLen = 0;

	if (this->_str == "-inff" || this->_str == "+inff" || this->_str == "nanf" 
		|| this->_str == "-inf" || this->_str == "+inf" || this->_str == "nan") {
		if (this->_str == "-inff" || this->_str == "-inf")
			return (-1.0 / 0.0);
		else if (this->_str == "+inff" || this->_str == "+inf")
			return (1.0 / 0.0);
		else if (this->_str == "nanf" || this->_str == "nan")
			return (0.0 / 0.0);
	}
	if (this->_str[i] == '-') {
		sign = -1;
		i++;
	}
	else if (this->_str[i] == '+')
		i++;
	if (this->_str[i] == '\0')
		throw Casting::ImpossibleException();
	while (i < len) {
		if (isdigit(this->_str[i]))
			num = num * 10 + (this->_str[i] - '0');
		else if (this->_str[i] == '.') {
			i++;
			while (i < len) {
				if (isdigit(this->_str[i])) {
					dec = dec * 10 + (this->_str[i] - '0');
					decLen++;
				} else if (this->_str[i] == 'f' && i == len - 1)
					break;
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

char	Casting::getChar() const {
	int	c;

	try {
		c = this->StringToInt();
		if (!isascii(c))
			throw Casting::ImpossibleException();
	} catch (...) {
		throw Casting::ImpossibleException();
	}
	if (!isprint(c))
		throw Casting::NonDisplayableException();
	return static_cast<char>(c);
}

int		Casting::getInt() const {
	int	i;

	try {
		i = this->StringToInt();
	} catch (...) {
		throw Casting::ImpossibleException();
	}
	return i;
}

float	Casting::getFloat() const {
	float	f;

	try {
		f = this->StringToFloat();
	} catch (...) {
		throw Casting::ImpossibleException();
	}
	return f;
}

double	Casting::getDouble() const {
	double	d;

	try {
		d = this->StringToDouble();
	} catch (...) {
		throw Casting::ImpossibleException();
	}
	return d;
}

std::ostream &operator << (std::ostream &out, Casting const &cast) {

	out << "char: ";
	try {
		out << cast.getChar() << endl;
	} catch (std::exception &e) {
		out << e.what() << endl;
	}
	out << "int: ";
	try {
		out << cast.getInt() << endl;
	} catch(std::exception& e) {
		out << e.what() << endl;
	}
	out << "float: ";
	try {
		double f = cast.getFloat();

		if (isnan(f) && signbit(f))
			out << "-";
		out << f;
		if (!isnan(f) && f - static_cast<int>(f) == 0)
			out << ".0";
		out << "f" << std::endl;
	} catch(std::exception& e) {
		out << e.what() << endl;
	}
	out << "double: ";
	try {
		double d = cast.getDouble();

		if (isnan(d) && signbit(d))
			out << "-";
		out << d;
		if (!isnan(d) && d - static_cast<int>(d) == 0)
			out << ".0";
		out << std::endl;
	} catch(std::exception& e) {
		out << e.what() << endl;
	}
	return out;
}
