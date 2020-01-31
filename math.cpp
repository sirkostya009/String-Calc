#include <string>

// these funcs are being told about in comments of ids.cpp
long getFirstInt(int j, std::string str);
long getSecondInt(int j, std::string str);

// gets two integers and divides them, simple
long division(int j, std::string str) {
	long first{ getFirstInt(j, str) };
	long second{ getSecondInt(j, str) };

	return first / second;
}

// gets two integers and multiplies them
long long multiplication(int j, std::string str) {
	long first{ getFirstInt(j, str) };
	long second{ getSecondInt(j, str) };

	return first * second;
}

// gets two integers and adds them
long long addition(int j, std::string str) {
	long first{ getFirstInt(j, str) };
	long second{ getSecondInt(j, str) };

	return first + second;
}

// gets two integers and substracts them
long substraction(int j, std::string str) {
	long first{ getFirstInt(j, str) };
	long second{ getSecondInt(j, str) };

	return first - second;
}
