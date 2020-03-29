/**
 *  Name: Extended Euclid
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>
#define long long ll;

using namespace std;

/** 

#define pii pair<ll, ll>
#define x first
#define y second

pii egcd(ll a, ll b) {
	if(b == 0) {
		return pii(1, 0);
	}

	pii d = egcd(b, a % b);
	return pii(d.y, d.x - d.y * (a / b));
}

*/

ll egcd(ll a, ll b, ll& x, ll& y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll xx, yy;
	ll gcd = egcd(b, a % b, xx, yy);
    
    x = yy;
    y = xx - yy * (a / b);
	return gcd;
}

int main()
{
	ll a, b, x, y, gcd;

	cin >> a >> b;
	gcd = egcd(a, b, x, y);
	cout << x << " " << y << " " << gcd << endl;

	return 0;
}