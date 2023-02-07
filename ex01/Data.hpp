#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

using std::cout;
using std::endl;

class Data {

private:

	int		_int;
	char	_char;

public:

	Data();
	Data(Data const &data);
	Data &operator=(Data const &data);
	~Data();

};

#endif
