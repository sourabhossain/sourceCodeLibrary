/**
 *  Name: Is Fibonicci
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

long long squareRoot(long long n) {
	if(n < 2) {
		return n;
	}

	long long left = 1, right = n, mid, temp;

	while(left <= right) {
		mid = left + (right - left) / 2;
		temp = n / mid;

		if(temp == mid) {
			return mid;
		}

		if(temp > mid) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return right;
}

bool isPerfectSquare(long long n) {
	long long root = squareRoot(n);
	return root * root == n;
}

bool isFibonicci(long long n) {
	return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

int main()
{
	long long n;

	cin >> n;
	cout << isFibonicci(n) << endl;

	return 0;
}