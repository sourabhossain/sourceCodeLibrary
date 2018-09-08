/**
  *  Name: Bit Prime Number
  *  Author Name: Sourav Hossain
  */

#include <bits/stdc++.h>
#define SIZE 100000002

int prime[SIZE/64 + 2];

#define CHECK(n) (prime[n / 64] & (1 << ((n % 64) / 2)))
#define SET(n) (prime[n / 64] |= (1 << ((n % 64) / 2)))

void sieve() {
	int root = sqrt(SIZE);

	for(int i = 3; i <= root; i += 2) {
		if(CHECK(i) == false) {
			for(int j = i * i; j < SIZE; j += i << 1) {
				SET(j);
			}
		}
	}
} // end sieve function

bool isPrime(int n) {
	return n > 1 && (n == 2 || ((n & 1) && !CHECK(n)));
} // end isPrime function

int main()
{
	sieve(); // go to sieve function
	int T, n;

	scanf("%d", &T);

	while(T--) {
		scanf("%d", &n);

		if(isPrime(n)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}

	return 0;
}