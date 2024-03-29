#include<iostream>
#include<algorithm>
#include<vector>
#include "LotteryNumbers.h"

using namespace std;

vector<int> generateRandomNumbers(int n) {
	cout << endl;
	vector<int> randomNumbers;
	int i = 0;
	while (i < n) {
	Randomnumber: int num = rand() % 39 + 1; // generates random number between 1-39 

		// check if num already exist in randomNumbers array
		if (find(begin(randomNumbers), end(randomNumbers), num) == end(randomNumbers)) {
			//if doesnot exist, add num to randomNumbers array
			randomNumbers.push_back(num);
		}
		else {
			//if num already exist in array, goto Randomnumber
			goto Randomnumber;
		}

		i++;
	}

	//sort randomNumbers in descending order
	sort(randomNumbers.begin(), randomNumbers.end(), greater<int>());

	return randomNumbers;
}


vector<int> getUserNumbers(int n) {
	vector<int> userNumbers;
	string generateAutomatically;
	cout << "\nType 'yes' if you want the numbers to be generated automatically. If not press any key and enter: \n";
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
		cout << "Oh no!! Please, try again."<< endl ;
	}
}