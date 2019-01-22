/**
 *  Name: nPr
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

unsigned long long nPr(int n, int r) {
	unsigned long long result = 1;

	while(r--) {
		result *= n--;
	}

	return result;
} 

int main()
{
	int n, r;

	cin >> n >> r;
	cout << nPr(n, r) << endl;

	return 0;
}