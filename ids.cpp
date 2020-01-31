#include <string>
#include <cmath>

int id1stNum_finder(int j, std::string str) {
	int id1stNum{ j };
	while (true) {
		--id1stNum;
		if ((str[id1stNum] == '+' || str[id1stNum] == '-' || str[id1stNum] == '*' || str[id1stNum] == '/') || id1stNum == 0) {
			id1stNum += (id1stNum == 0) ? 0 : 1;
			break;
		}
	}

	return id1stNum;
}

int id2ndNum_finder(int j, std::string str) {
	int id2ndNum{ j };
	while (true) {
		++id2ndNum;
		if ((str[id2ndNum] == '+' || str[id2ndNum] == '-' || str[id2ndNum] == '/' || str[id2ndNum] == '*') || id2ndNum == str.length()) {
			return id2ndNum;
		}
	}
}

long getFirstInt(int j, std::string str) {
	int id1stNum{ id1stNum_finder(j, str) };
	long result{};
	for (int i{ id1stNum }; i < j; ++i) {
		result += (str[i] - '0') * std::pow(10, j - i - 1);
	}

	return result;
}

long getSecondInt(int j, std::string str) {
	int id2ndNum{ id2ndNum_finder(j, str) };

	long result{};
	for (int i{ j + 1 }; i < id2ndNum; ++i) {
		result += (str[i] - '0') * std::pow(10, id2ndNum - i - 1);
	}

	return result;
}
