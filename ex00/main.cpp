#include "Casting.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		cout << "Error: Wrong number of arguments" << endl;
		return 1;
	}
	Casting casting(av[1]);
	cout << casting;
	return 0;
}

/*
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

bool checkDouble(string s) {
	int decimal = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i]) && s[i] != '.') {
			return false;
		}
		if (s[i] == '.') {
			decimal++;
		}
		if (decimal > 1) {
			return false;
		}
	}
	return true;
}

bool checkInt(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}

bool checkChar(string s) {
	if (s.size() == 1) {
		int num = atoi(s.c_str());
		if (num >= 0 && num <= 255) {
			return true;
		}
	}
	return false;
}

string checkType(string s) {
	if (checkChar(s)) {
		return "char";
	} else if (checkInt(s)) {
		return "int";
	} else if (checkDouble(s)) {
		return "double";
	} else {
		return "string";
	}
}

int main() {
	string input;
	cin >> input;
	cout << checkType(input) << endl;
	return 0;
}
*/

// #include <iostream>
// #include <string>
// #include <sstream>

// using namespace std;

// int main() {
//   string input;
//   cout << "Enter a number: ";
//   cin >> input;

//   char c = input[input.length() - 1];
//   if (c == 'f') {
//     float value;
//     stringstream ss(input);
//     ss >> value;
//     cout << "The input is a float: " << value << endl;
//   } else if (c == '.') {
//     double value;
//     stringstream ss(input);
//     ss >> value;
//     cout << "The input is a double: " << value << endl;
//   } else {
//     int value;
//     stringstream ss(input);
//     ss >> value;
//     if (value >= 0 && value <= 255) {
//       cout << "The input is a char: " << (char)value << endl;
//     } else {
//       cout << "The input is an int: " << value << endl;
//     }
//   }

//   return 0;
// }