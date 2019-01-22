/**
  *  Name: Big Fibonacci Number
  *  Author Name: Sourav Hossain
  */

#include <bits/stdc++.h>
#define SIZE 1001

using namespace std;

string bigAddition(string first, string second) {
	if(first.size() > second.size()) {
		swap(first, second);
	}

	string result = "";
	int firstLength = first.size(), secondLength = second.size();
	int carry = 0, difference = secondLength - firstLength;

	for(int i = firstLength - 1; i >= 0; i--) {
		carry += (first[i] - '0') + (second[i + difference] - '0');
	    result = to_string(carry % 10) + result;
	    carry /= 10;
	}

	for(int i = difference - 1; i >= 0; i--) {
		carry += (second[i] - '0');
		result = to_string(carry % 10) + result;
		carry /= 10;
	}

	return (carry)? to_string(carry) + result : result;
}

int main(int argc, char const *argv[])
{
    string fibonacci[SIZE];

    fibonacci[0] = "0";
    fibonacci[1] = fibonacci[2] = "1";

    for(int i = 3; i < SIZE; i++) {
        fibonacci[i] = bigAddition(fibonacci[i - 1], fibonacci[i - 2]);
    }

    int n;

    cin >> n;
    cout << fibonacci[n] << endl;

	return 0;
}