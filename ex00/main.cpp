#include "Casting.hpp"
#include "Scalar.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		cout << "Error: Wrong number of arguments" << endl;
		return 1;
	}
	// Casting casting(av[1]);
	// cout << casting << endl;
	Scalar scalar(av[1]);

	std::cout << scalar;
	return 0;
}