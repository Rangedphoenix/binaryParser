/********************************************
*	CS321: Data Structures and Algorithms
*	Subject: 
*	Programmer: Brandon Barnhard
*	Date: 
*	Filename: 
********************************************/

#include <iostream>
#include <cmath>
#include <stack>
#include <sstream>


using namespace std;

int Convert(stack<int>, int);

int main() {
	stringstream ss;
	string holder;
	stack<int> binaryNumSplit;
	bool errorRead = false;
	
	cout << "Please enter the binary number you wish to convert to decimal format: ";
	cin >> holder;

	ss << holder;

	//convert the numbers into the stack
	for (int i = 0; i < ss.str().size(); i++) {
		if (ss.str()[i] == '0') {
			binaryNumSplit.push(0);
		}
		else if (ss.str()[i] == '1') {
			binaryNumSplit.push(1);
		}
		else {
			errorRead = true;
		}
	}

	if (errorRead == true) {
		cout << "Error reading input, exiting...\n";
		return 1;
	}

	int size = binaryNumSplit.size();

	cout << "Number converted to decimal is: " << Convert(binaryNumSplit, 0) << endl;

	cout << endl;
	
	return 0;
}


int Convert(stack<int> nums, int weight) {
	if (nums.size() == 0) {
		return 0;
	}

	int curTop = nums.top();
	nums.pop();

	int total = Convert(nums, weight + 1);
	total += curTop * pow(2, weight);

	return total;
}