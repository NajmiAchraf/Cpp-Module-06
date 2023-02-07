#include "Data.hpp"

Data::Data() : _int(0), _char(0) {
	cout << "Data constructor called" << endl;
}

Data::Data(Data const &data) {
	cout << "Data copy constructor called" << endl;
	*this = data;
}

Data &Data::operator=(Data const &data) {
	cout << "Data assignation operator called" << endl;
	if (this != &data) {
		_int = data._int;
		_char = data._char;
	}
	return *this;
}

Data::~Data() {
	cout << "Data destructor called" << endl;
}
