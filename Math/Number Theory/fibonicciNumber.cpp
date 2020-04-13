/**
 * Name: Fibonicci Number
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void tn(long long a[2][2], long long n, long long MOD) {
	if(n == 1) {
		return;
	}

	tn(a, n >> 1, MOD);

	long long u = ((a[0][0] * a[0][0]) % MOD + (a[0][1] * a[1][0]) % MOD) % MOD;
	long long v = ((a[0][0] * a[0][1]) % MOD + (a[0][1] * a[1][1]) % MOD) % MOD;
	long long w = ((a[1][0] * a[0][0]) % MOD + (a[1][1] * a[1][0]) % MOD) % MOD;
	long long x = ((a[1][0] * a[0][1]) % MOD + (a[1][1] * a[1][1]) % MOD) % MOD;
    
    a[0][0] = u, a[0][1] = v, a[1][0] = w, a[1][1] = x;

    if(n & 1) {
    	u = a[0][1];
    	v = (a[0][0] + a[0][1]) % MOD;
    	w = a[1][1];
    	x = (a[1][0] + a[1][1]) % MOD;
    	a[0][0] = u, a[0][1] = v, a[1][0] = w, a[1][1] = x;
    }
}

long long fibonicci(int n, long long MOD) {
    long long T[2][2] = {{0, 1}, {1, 1}};
    tn(T, n, MOD);
    return T[1][0] % MOD;	
}

int main()
{
	for(int i = 1; i <= 10; i++) {
		printf("%lld ", fibonicci(i, 1000));
	}
	putchar('\n');

	return 0;
}