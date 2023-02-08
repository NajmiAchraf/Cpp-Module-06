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
		cout << "pointer A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "pointer B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "pointer C" << endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		cout << "reference A" << endl;
		(void)a;
		
	} catch(...) {} // {cout << "reference A faild" << endl;}
	try {
		B &b = dynamic_cast<B &>(p);
		cout << "reference B" << endl;
		(void)b;
	} catch(...) {} // {cout << "reference B faild" << endl;}
	try {
		C &c = dynamic_cast<C &>(p);
		cout << "reference C" << endl;
		(void)c;
	} catch(...) {} // {cout << "reference C faild" << endl;}

}

int main() {
	Base *base = generate();
	identify(base);
	identify(*base);
}

