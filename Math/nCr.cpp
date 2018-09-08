/**
 *  Name: nCr
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

long long nCr(int n, int r) {
	if(r > n / 2) {
		r = n - r;
	}

	int ans = 1;

	for(int i = 1; i <= r; i++) {
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}

int main()
{
	int n, r;

	cin >> n >> r;
	cout << nCr(n, r) << endl;

	return 0;
}