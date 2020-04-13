/**
 *  Name: Derangement Number
 *  Author Name: Sourab Hossain 
 */

#include <bits/stdc++.h>
#define SIZE 51

using namespace std;

unsigned long long derangement[SIZE];

void derangementNumber() {
	derangement[0] = 1;
	derangement[1] = 0;
	derangement[2] = 1;

	for(int i = 3; i < SIZE; i++) {
		derangement[i] = (i - 1) * (derangement[i - 1] + derangement[i - 2]);
	}
}

int main()
{
	derangementNumber();
	int n;

	cin >> n;
	cout << derangement[n] << endl;

	return 0;
}