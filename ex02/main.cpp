#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	srand(time(0)); // Initialize random number generator.
	int random = rand() % 12;
	for (int i = 0; i < random; i++) {
		random = rand() % 12;
	}
	int i = random % 3;
	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "C" << endl;
}

void identify(Base &p) {
	if (dynamic_cast<A*>(&p))
		cout << "A" << endl;
	else if (dynamic_cast<B*>(&p))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(&p))
		cout << "C" << endl;
}

int main() {
	Base *base = generate();
	identify(base);
	identify(*base);
}

