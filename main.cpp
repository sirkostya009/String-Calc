#include <iostream>

int id1stNum_finder(int j, std::string str);
int id2ndNum_finder(int j, std::string str);

long getFirstInt(int j, std::string str);
long getSecondInt(int j, std::string str);

long division(int j, std::string str);
long long multiplication(int j, std::string str);
long long addition(int j, std::string str);
long substraction(int j, std::string str);

int addition_and_substraction(std::string str);
int division_and_multi(std::string str);

std::string elimination(int j, long long replacement, std::string str, bool isLast);

void doMath(std::string str) {
	int localvar{ division_and_multi(str) };

	int isLast{ division_and_multi(str) + addition_and_substraction(str) - 1 };

	unsigned __int64 size{ str.length() };
	for (int i{}; i < size; ++i) {
		if (str[i] == '/') {
			--localvar;
			--isLast;
			str = elimination(i, division(i, str), str, isLast);
			i = -1;
			size = str.length();
			continue;
		}

		if (str[i] == '*') {
			--localvar;
			--isLast;
			str = elimination(i, multiplication(i, str), str, isLast);
			i = -1;
			size = str.length();
			continue;
		}

		if (!localvar) break;
	}

	size = str.length();
	localvar = addition_and_substraction(str);

	for (int i{}; i < size; ++i) {
		if (str[i] == '+') {
			--localvar;
			--isLast;
			str = elimination(i, addition(i, str), str, isLast);
			i -= 1;
			size = str.length();
			continue;
		}

		if (str[i] == '-') {
			--localvar;
			--isLast;
			str = elimination(i, substraction(i, str), str, isLast);
			i -= 1;
			size = str.length();
			continue;
		}

		if (!localvar) break;
	}

	std::cout << str;
}

int main() {
	std::string str{};
	
	std::cin >> str;

	doMath(str);
}