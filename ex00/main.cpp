#include "Casting.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		cout << "Error: Wrong number of arguments" << endl;
		return 1;
	}
	try {
		Casting casting(av[1]);
		cout << casting;
	} catch (...) {}
	return 0;
}
