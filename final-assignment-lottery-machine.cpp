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

