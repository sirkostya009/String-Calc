#include <string>
#include <cmath>

/*
* id1stNum_finder is a func that finds where first number begins to exist
* example:
* "11-4", first number here is 11, it begins from index 0 in string
*/
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
/*
* same goes to id2ndNum_finder
* example:
* "11-4", second number here is 4, but 2ndNum_finder seeks where it ends -
* - in our case, it's 4, or length of our string;
*/
int id2ndNum_finder(int j, std::string str) {
	int id2ndNum{ j };
	while (true) {
		++id2ndNum;
		if ((str[id2ndNum] == '+' || str[id2ndNum] == '-' || str[id2ndNum] == '/' || str[id2ndNum] == '*') || id2ndNum == str.length()) {
			return id2ndNum;
		}
	}
}

/*
* basically what it does is getting first int, in case of str = "11-4" -
* - it would return 11, where j is where the mathematical operator is located -
* - index 2.
* so, it parses all chars from indexes id1stNum (including) till the j.
*/
long getFirstInt(int j, std::string str) {
	int id1stNum{ id1stNum_finder(j, str) };
	long result{};
	for (int i{ id1stNum }; i < j; ++i) {
		result += (str[i] - '0') * std::pow(10, j - i - 1);
	}

	return result;
}

/*
* this one does the same thing but in different order
* it gets all the integers from 'j' (excluding it) till id2ndNum (excluding)
*/
long getSecondInt(int j, std::string str) {
	int id2ndNum{ id2ndNum_finder(j, str) };

	long result{};
	for (int i{ j + 1 }; i < id2ndNum; ++i) {
		result += (str[i] - '0') * std::pow(10, id2ndNum - i - 1);
	}

	return result;
}
