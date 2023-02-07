#include "Casting.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		cout << "Error: Wrong number of arguments" << endl;
		return 1;
	}
	Casting casting(av[1]);
	cout << casting << endl;
	return 0;
}