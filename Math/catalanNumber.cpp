/**
 *  Name: Catalan Number
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

unsigned long long catalanNumber(int n) {
	if(n < 2) {
		return 1;
	}

	unsigned long long result = 0;

	for(int i = 0; i < n; i++) {
		result += catalanNumber(i) * catalanNumber(n - i - 1);
	}

	return result;
}

int main()
{
	int n;

	cin >> n;
	cout << catalanNumber(n) << endl;
	
	return 0;
}