/**
 *  Name: nCr
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

unsigned long long nCr(int n, int r) {
	int ans = 1;
	r = min(r, n - r);

	for(int i = 1; i <= r; i++) {
		ans = (ans * n--) / i;
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