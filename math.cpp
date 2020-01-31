#include <string>

long getFirstInt(int j, std::string str);
long getSecondInt(int j, std::string str);

long division(int j, std::string str) {
	long first{ getFirstInt(j, str) };
	long second{ getSecondInt(j, str) };

	return first / second;
}

long long multiplication(int j, std::string str) {
	long first{ getFirstInt(j, str) };
	long second{ getSecondInt(j, str) };

	return first * second;
}

long long addition(int j, std::string str) {
	long first{ getFirstInt(j, str) };
	long second{ getSecondInt(j, str) };

	return first + second;
}

long substraction(int j, std::string str) {
	long first{ getFirstInt(j, str) };
	long second{ getSecondInt(j, str) };

	return first - second;
}