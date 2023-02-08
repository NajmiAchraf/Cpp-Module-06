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


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		return 1;
	}
	std::string str(av[1]);
	// char
	if (str.length() == 1)
	{
		std::cout << "char: ";
		if (isdigit(str[0]) || (static_cast<int>(str[0]) >= 32 && static_cast<int>(str[0]) <= 126))
			std::cout << "\'" << str[0] << "\'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << (isdigit(str[0]) ? static_cast<int>(str[0]) - 48 : static_cast<int>(str[0])) << std::endl;
		std::cout << "float: " << (isdigit(str[0]) ? static_cast<float>(str[0]) - 48 : static_cast<float>(str[0])) << ".0f" << std::endl;
		std::cout << "double: " << (isdigit(str[0]) ? static_cast<double>(str[0]) - 48 : static_cast<double>(str[0])) << ".0" << std::endl;
	}
	// int
	else if (str.find_first_not_of("0123456789-") == std::string::npos)
	{
		std::cout << "char: ";
		if (static_cast<char>(atoi(av[1])) >= 32 && static_cast<char>(atoi(av[1])) <= 126)
			std::cout << "\'" << static_cast<char>(atoi(av[1])) << "\'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << atoi(av[1]) << std::endl;
		std::cout << "float: " << static_cast<float>(atoi(av[1])) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(atoi(av[1])) << ".0" << std::endl;
	}
	// float
	else if (str == "nan" || str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff" || str == "nanf" || str.find_first_not_of("0123456789.-f") == std::string::npos)
	{
		if (str == "nan" || str == "-inf" || str == "+inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << str << "f" << std::endl;
			std::cout << "double: " << str << std::endl;
		}
		else if (str == "-inff" || str == "+inff" || str == "nanf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << str << std::endl;
			str.resize(4);
			std::cout << "double: " << str << std::endl;
		}
		else
		{
			std::cout << "char: ";
			if (static_cast<int>(atof(av[1])) >= 32 && static_cast<int>(atof(av[1])) <= 126)
				std::cout << "\'" << static_cast<char>(atof(av[1])) << "\'" << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
			std::cout << "int: " << static_cast<int>(atof(av[1])) << std::endl;
			std::cout << "float: " << atof(av[1]) << ((atof(av[1]) == roundf(atof(av[1]))) ? ".0" : "") << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(atof(av[1])) << (static_cast<double>(atof(av[1])) == roundl(static_cast<double>(atof(av[1]))) ? ".0" : "") << std::endl;
		}
	}
	else
	{
		std::cout << "Error: invalid argument" << std::endl;
		return 1;
	}
}