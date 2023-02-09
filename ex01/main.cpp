#include "Data.hpp"
#include <cstdio>
#include <iostream>

#define HEX_BASE 16

std::string dectohex(uintptr_t decimal) {
	char		hexaDecimal[100];
	int			i = 0;
	std::string out = "";

	while (decimal != 0) {
		int temp = 0;
		temp = decimal % HEX_BASE;
		if (temp < 10) {
			hexaDecimal[i] = temp + 48;
			i++;
		} else {
			hexaDecimal[i] = temp + 55;
			i++;
		}
		decimal = decimal / HEX_BASE;
	}
	for (int j = i - 1; j >= 0; j--) {
		out = out + hexaDecimal[j];
	}
	return ("0x" + out);
}

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main() {
	Data		*data1	= new Data();
	uintptr_t	raw		= serialize(data1);
	Data		*data2	= deserialize(raw);

	data1->_int = 1;
	data1->_char = 'c';

	std::cout << "before data1->_int = " << data1->_int << std::endl;
	std::cout << "before data1->_char = " << data1->_char << std::endl;
	std::cout << "Pointed address of data1 " << data1 << " equal to pointed address of data2 " << data2;
	std::cout << " pointed address of raw " << dectohex(raw) << std::endl;
	std::cout << "after data2->_int = " << data2->_int << std::endl;
	std::cout << "after data2->_char = "  << data2->_char << std::endl;
	delete data1;
	return 0;
}
