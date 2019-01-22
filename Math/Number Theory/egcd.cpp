/**
 *  Name: Extended Euclid
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

/** 

#define pii pair<int, int>
#define x first
#define y second

pii egcd(long long a, long long b) {
	if(b == 0) {
		return pii(1, 0);
	}

	pii d = egcd(b, a % b);
	return pii(d.y, d.x - d.y * (a / b));
}

*/

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