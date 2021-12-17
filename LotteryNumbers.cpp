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