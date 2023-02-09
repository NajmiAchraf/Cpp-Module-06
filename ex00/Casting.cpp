#include "Casting.hpp"

char	Casting::getChar() const {
	if (this->_flag) {
		try {
			if (!isascii(static_cast<int>(this->_char)))
				throw Casting::ImpossibleException();
		} catch (...) {
			throw Casting::ImpossibleException();
		}
		if (!isprint(static_cast<int>(this->_char)))
			throw Casting::NonDisplayableException();
		return this->_char;
	}
	else
		throw Casting::ImpossibleException();
	return this->_char;
}

int		Casting::getInt() const {
	if (this->_flag)
		return this->_int;
	else
		throw ImpossibleException();

	return this->_int;
}

float	Casting::getFloat() const {
	if (this->_flag)
		return this->_float;
	else
		throw ImpossibleException();
	return this->_float;
}

double	Casting::getDouble() const {
	if (this->_flag)
		return this->_double;
	else
		throw ImpossibleException();
	return this->_double;
}

string	Casting::getStr() const {
	return this->_str;
}

Casting::Casting() {
	cout << "Default constructor" << endl;
}

Casting::Casting(string str) : _str(str) {
	cout << C_GREEN << "Parameterize constructor" << endl
		<< C_CYAN << "The entred string is : " << _str << C_RES << endl;
	try {
		fillType();
		_flag = true;
	} catch (...) {}
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

int		Casting::StringToInt() {
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

float	Casting::StringToFloat() {
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

double	Casting::StringToDouble() {
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

char	Casting::getChar() {
	return static_cast<char>(this->StringToInt());
}

int		Casting::getInt() {
	int	i;

	try {
		i = this->StringToInt();
	} catch (...) {
		throw Casting::ImpossibleException();
	}
	return static_cast<int>(i);
}

float	Casting::getFloat() {
	float	f;

	try {
		f = this->StringToFloat();
	} catch (...) {
		throw Casting::ImpossibleException();
	}
	return static_cast<float>(f);
}

double	Casting::getDouble() {
	double	d;

	try {
		d = this->StringToDouble();
	} catch (...) {
		throw Casting::ImpossibleException();
	}
	return static_cast<double>(d);
}


int		Casting::checkType() {
	int i = 0;
	int len = this->_str.length();
	bool point = false;
	int num = 0;
	int decLen = 0;
	int type = -1; // 0: char, 1: int, 2: float, 3: double

	if (this->_str[i] == '-' || this->_str[i] == '+')
		i++;
	if (this->_str[i] == '\0')
		return type;
	while (i < len) {
		if (isdigit(this->_str[i]))
			num++;
		else if (this->_str[i] == '.') {
			if (point || i == len - 1)
				break;
			point = true;
			i++;
			while (i < len) {
				if (isdigit(this->_str[i])) {
					decLen++;
				} else if (this->_str[i] == 'f' && i == len - 1)
					break;
				else
					break;
				i++;
			}
			break;
		}
		else
			break;
		i++;
	}
	if (decLen > 0) {
		if (this->_str[len - 1] == 'f'  && i == len - 1)
			type = 2;
		else if (i == len)
			type = 3;
	} else if (num > 0 && i == len) {
		if (len == 1)
			type = 0;
		else
			type = 1;
	}
	if (type == -1) {
		if (this->_str == "+inff" || this->_str == "-inff" || this->_str == "nanf")
			type = 2;
		else if (this->_str == "+inf" || this->_str == "-inf" || this->_str == "nan")
			type = 3;
	}
	return type;
}


void	Casting::fillType() {
	this->_type = this->checkType();
	cout << "type: ";
	if (this->_type == 0)
		cout << "char";
	else if (this->_type == 1)
		cout << "int";
	else if (this->_type == 2)
		cout << "float";
	else if (this->_type == 3)
		cout << "double";
	else
		cout << "impossible";
	cout << endl;
	try {
		if (this->_type == 0) {
			this->_char = this->getChar();
			this->_int = static_cast<int>(this->_char);
			this->_float = static_cast<float>(this->_char);
			this->_double = static_cast<double>(this->_char);
		} else if (this->_type == 1) {
			this->_int = this->getInt();
			this->_char = static_cast<char>(this->_int);
			this->_float = static_cast<float>(this->_int);
			this->_double = static_cast<double>(this->_int);
		} else if (this->_type == 2) {
			this->_float = this->getFloat();
			this->_char = static_cast<char>(this->_float);
			this->_int = static_cast<int>(this->_float);
			this->_double = static_cast<double>(this->_float);
		} else if (this->_type == 3) {
			this->_double = this->getDouble();
			this->_char = static_cast<char>(this->_double);
			this->_int = static_cast<int>(this->_double);
			this->_float = static_cast<float>(this->_double);
		} else {
			_flag = false;
			throw Casting::ImpossibleException();
		}
	} catch (std::exception &e) {
		_flag = false;
		throw Casting::ImpossibleException();
	}
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
		float f = cast.getFloat();

		// if (isnan(f) && signbit(f))
		// 	out << "-";
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

		// if (isnan(d) && signbit(d))
		// 	out << "-";
		out << d;
		if (!isnan(d) && d - static_cast<int>(d) == 0)
			out << ".0";
		out << std::endl;
	} catch(std::exception& e) {
		out << e.what() << endl;
	}
	return out;
}
