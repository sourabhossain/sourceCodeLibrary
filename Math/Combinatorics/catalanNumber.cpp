/**
 *  Name: Catalan Number
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

unsigned long long catalan(int n) {
	unsigned long long c = 1;

	for(int i = 2; i <= n; i++) {
		c = (2 * (2 * i - 1) * c) / (i + 1);
	}

	return c;
}

int main()
{
	for(int i = 0; i <= 15; i++) {
		cout << catalan(i) << " ";
	}
	cout << endl;

	return 0;
}