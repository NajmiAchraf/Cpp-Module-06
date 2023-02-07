#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main(int ac, char **av) {
	Data		*data1	= new Data();
	uintptr_t	raw		= serialize(data1);
	Data		*data2	= deserialize(raw);

	cout << "Pointed address of data1 " << data1 << " equal to pointed address of data2 " << data2 << endl;
	delete data1;
	return 0;
}