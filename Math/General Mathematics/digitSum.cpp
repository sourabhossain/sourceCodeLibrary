/**
 *  Name: Digit Sum
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int digitSum(int n) {
	if(n < 10) {
		return n;
	}

	return digitSum(digitSum(n / 10) + n % 10);
}

/**

int digitSum(int n) {
	if(n < 10) {
		return n;
	}

	return digitSum(n / 10) + n % 10;
}

**/

/**

int digitSum(int n) {
	int sum = 0;

	while(n) {
		sum += (n % 10);
		n /= 10;
	}

	return sum;
}

**/

int main(int argc, char const *argv[])
{
	int n;

	cin >> n;
	cout << digitSum(n) << endl;

	return 0;
}