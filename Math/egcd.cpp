/**
 *  Name: Extended Euclid
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

long long egcd(long long a, long long b, long long& x, long long& y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	long long xx, yy;
	long long gcd = egcd(b, a % b, xx, yy);
    
    x = yy;
    y = xx - yy * (a / b);
	return gcd;
}

int main()
{
	long long a, b, x, y;

	cin >> a >> b;
	long long gcd = egcd(a, b, x, y);
	cout << x << " " << y << " " << gcd << endl;

	return 0;
}