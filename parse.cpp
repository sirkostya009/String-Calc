#include <string>

long id1stNum_finder(int j, std::string str);
long id2ndNum_finder(int j, std::string str);

int getNumOfNums(long long integer) {
	int ret{};

	while (integer > 0) {
		integer /= 10;
		++ret;
	}

	return ret;
}

std::string llToString(long long integer) {
	std::string str{};

	int length{ getNumOfNums(integer) };
	for (int i{}; i < length; ++i) {
		str += (static_cast<char>((integer % 10) + '0'));
		integer /= 10;
	}

	std::string ret{};
	for (int i{ static_cast<int>(str.length() - 1) }; i >= 0; --i) {
		ret += str[i];
	}

	return ret;
}

std::string elimination(int j, long long replacement, std::string str, bool isLast) {
	int id1stNum{ id1stNum_finder(j, str) };
	int id2ndNum{ id2ndNum_finder(j, str) };

	std::string ret{};
	bool eliminated{ false };
	for (int i{}; i < str.size(); ++i) {
		if (i >= id1stNum and i < id2ndNum)
			continue;

		if (i >= id2ndNum)
			if (!eliminated) {
				ret += llToString(replacement);
				eliminated = true;
			}

		ret += str[i];
	}

	if (isLast && !eliminated) ret += llToString(replacement);

	return ret;
}

int division_and_multi(std::string str) {
	int ret{};

	for (int i{}; i < str.length(); ++i) {
		if (str[i] == '*' || str[i] == '/') ++ret;
	}

	return ret;
}

int addition_and_substraction(std::string str) {
	int ret{};

	for (int i{}; i < str.length(); ++i) {
		if (str[i] == '+' || str[i] == '-') ++ret;
	}

	return ret;
}