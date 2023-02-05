#include "Convert.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Error: Wrong number of arguments" << endl;
		return 1;
	}
	Convert convert(argv[1]);
	convert.printAll();
	return 0;
}