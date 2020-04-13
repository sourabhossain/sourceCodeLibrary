/**
 * Name: Miller-Rabin Primality Test
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int power(int b, unsigned int p, int m) {
	int result = 1;
	b %= m;

	while(p) {
		if(p & 1) {
			result = (result * b) % m;
		}

		p >>= 1;
		b = (b * b) % m;
	}

	return result;
}

bool miillerTest(int d, int n) {
	int b = 2 + rand() % (n - 4);
	int p = power(b, d, n);

	if(p == 1 || p == n - 1) {
		return true;
	}

	while(d != n - 1) {
		p = (p * p) % n;
		d <<= 1;

		if(p == 1) {
			return false;
		}

		if(p == n - 1) {
			return true;
		}
	}

	return false;
}

bool isPrime(int n, int k) {
	if(n < 2) {
		return false;
	}

	if(n < 4) {
		return true;
	}

	if(n % 2 == 0 || n % 3 == 0) {
		return false;
	}

	int d = n - 1;

	while(d % 2 == 0) {
		d >>= 1;
	}

	for(int i = 0; i < k; i++) {
		if(!miillerTest(d, n)) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	int k = 4;

	for(int i = 1; i <= 100; i++) {
		if(isPrime(i, k)) {
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}