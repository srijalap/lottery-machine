#include<iostream>
#include<algorithm>
#include<vector>
#include "LotteryNumbers.h"

using namespace std;

struct User {
	vector<int> lotteryNumbers;
	vector<int> bonusNumbers;
};

User getUserLotteryNumbers();
vector<int> getUserNumbers(int n);
int compareLotteryNumbers(const vector<int> generatedLotteryNumbers, const vector<int> userLotteryNumbers);
void printLotteryResult(int matchedLotteryNumbers, int matchedBonusNumbers);

int main()
{
	// get different random numbers in every compilation
	// 
	srand((unsigned int)time(NULL));

	User srijana;
	User aashis;

	cout << "Srijana's Lottery: " << endl;
	srijana = getUserLotteryNumbers();

	cout << "Aashis's Lottery: " << endl;
	aashis = getUserLotteryNumbers();

	cout << endl << endl;

	// Get 7 random numbers and assign it to lottoNumbers vector
	vector<int> lottoNumbers = generateRandomNumbers(7);

	cout << "\nComputer generated lottery numbers are : \n";
	for (int i = 0; i < 7; i++) {
		cout << lottoNumbers[i] << " ";
	}

	// Get 3 random numbers and assign it to bonusNumbers vector
	vector<int> bonusNumbers = generateRandomNumbers(3);

	cout << "\n Computer generated bonus numbers are : \n";
	for (int number : bonusNumbers) {
		cout << number << " ";
	}

	cout << endl;

	int matchedLotteryNumbersSrijana = compareLotteryNumbers(lottoNumbers, srijana.lotteryNumbers);
	int matchedBonusNumbersSrijana = compareLotteryNumbers(bonusNumbers, srijana.bonusNumbers);
	cout << "\nLottery result for Srijana is " << matchedLotteryNumbersSrijana << " + " << matchedBonusNumbersSrijana << endl;

	printLotteryResult(matchedLotteryNumbersSrijana, matchedBonusNumbersSrijana);

	int matchedLotteryNumbersAashis = compareLotteryNumbers(lottoNumbers, aashis.lotteryNumbers);
	int matchedBonusNumbersAashis = compareLotteryNumbers(bonusNumbers, aashis.bonusNumbers);
	cout << "\nLottery result for Aashis is " << matchedLotteryNumbersAashis << " + " << matchedBonusNumbersAashis << endl;
	
	printLotteryResult(matchedLotteryNumbersAashis, matchedBonusNumbersAashis);

	return 0;
}

void printLotteryResult(int matchedLotteryNumbers, int matchedBonusNumbers) {
	string winningAmount;
	switch (matchedLotteryNumbers) {
	case 7:
		switch (matchedBonusNumbers) {
			case 3:
				winningAmount = "90 Million";
				break;
			case 2:
				winningAmount = "80 Million";
				break;
			case 1:
				winningAmount = "50 Million";
				break;
			default:
				winningAmount = "40 Million";
				break;
		}
		break;
	case 6:
		switch (matchedBonusNumbers) {
			case 3:
				winningAmount = "75 Million";
				break;
			case 2:
				winningAmount = "65 Million";
				break;
			case 1:
				winningAmount = "45 Million";
				break;
			default:
				winningAmount = "35 Million";
				break;
		}
		break;
	case 5:
		switch (matchedBonusNumbers) {
			case 3:
				winningAmount = "55 Million";
				break;
			case 2:
				winningAmount = "41 Million";
				break;
			case 1:
				winningAmount = "21 Million";
				break;
			default:
				winningAmount = "11 Million";
				break;
		}
		break;
	default:
		winningAmount = "0";
		break;
	}

	if (winningAmount != "0") {
		cout << "Congratulations!!! You won " << winningAmount << endl;
	}
	else {
		cout << "Oh no!! Please, try again.";
	}
}

User getUserLotteryNumbers() {
	User user;
	cout << "Lottery numbers: ";
	vector<int> user1LotteryNumbers = getUserNumbers(7);
	cout << "Bonus numbers: ";
	vector<int> user1BonusNumbers = getUserNumbers(3);

	cout << "\nLottery numbers are: ";
	for (int number : user1LotteryNumbers) {
		cout << number << " ";
	}

	cout << "\nBonus numbers are: ";
	for (int number : user1BonusNumbers) {
		cout << number << " ";
	}

	cout << endl << endl;

	user.lotteryNumbers = user1LotteryNumbers;
	user.bonusNumbers = user1BonusNumbers;

	return user;
}


vector<int> getUserNumbers(int n) {
	vector<int> userNumbers;
	string generateAutomatically;
	cout << "\nType 'yes' if you want the numbers to be generated automatically: \n";
	cin >> generateAutomatically;

	if (generateAutomatically == "yes") {
		return generateRandomNumbers(n);
	}
	else {
		int input;
		cout << "\nPlease enter " << n << " unique numbers between 1 and 39: \n";
		for (int k = 0; k < n; k++) {
		AskNumber: cin >> input;
			if (input > 39 || input < 1) {
				cout << "Number should be between 1 and 39. Please enter another number: \n";
				goto AskNumber;
			}

			if (find(begin(userNumbers), end(userNumbers), input) == end(userNumbers)) {
				// Push element to unserNumbers array
				userNumbers.push_back(input);
			}
			else {
				cout << input << " is duplicate. Please enter unique number: \n";
				goto AskNumber;
			}
		}

		cout << endl;

		sort(userNumbers.begin(), userNumbers.end(), greater<int>());

		return userNumbers;
	}
}



int compareLotteryNumbers(const vector<int> generatedLotteryNumbers, const vector<int> userLotteryNumbers) {
	// let 0 numbers are matched at first
	int matched = 0;

	for (int userNumber : userLotteryNumbers) {
		if (find(begin(generatedLotteryNumbers), end(generatedLotteryNumbers), userNumber) != end(generatedLotteryNumbers)) {
			// if userNumber exists in generatedLotteryNumbers, add 1 to matched
			matched++;
		}
	}

	return matched;
}
