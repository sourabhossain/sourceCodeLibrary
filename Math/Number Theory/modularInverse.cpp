/**
 *  Name: Modular Inverse
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int egcd(int a, int b, int& x, int& y) {
    if(b == 0) {
    	x = 1;
    	y = 0;
    	return a;
    }
    
    int xx, yy;
    int gcd = egcd(b, a % b, xx, yy);

    x = yy;
    y = xx - yy * (a / b);
    return gcd;	
}

int modularInverse(int a, int b) {
    int x, y;

    if(egcd(a, b, x, y) == 1) {
    	return (a % b + b) % b;
    }

    return -1;
}

int main()
{
	int a, b;

	cin >> a >> b;
	cout << modularInverse(a, b) << endl;

	return 0;
}