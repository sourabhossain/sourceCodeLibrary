/** 
 * Name: Modular Inverse  
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while(b) {
		b ^= a ^= b ^= a %= b;
	}
	
	return a;
}

int power(int b, int p, int m) {
	int result = 1;
    
    while(p) {
    	if(p & 1) {
    		result = ((result % m) * (b % m)) % m;
    	}

    	p >>= 1;
    	b = ((b % m) * (b % m)) % m;
    }

    return result;	
}

int modularInverse(int a, int b) {
	if(gcd(a, b) != 1) {
		return -1;
	}

	return power(a, b - 2, b);
}

int main(int argc, char const *argv[])
{
    int a, b;

	cin >> a >> b;
	cout << modularInverse(a, b) << endl;
    
    return 0;
}