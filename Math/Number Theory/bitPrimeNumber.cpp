/**
  *  Name: Bit Prime Number
  *  Author Name: Sourab Hossain
  */

#include <bits/stdc++.h>
#define SIZE 100000002

using namespace std;

int prime[(SIZE >> 6) + 2];

#define CHECK(n) (prime[n >> 6] & (1 << ((n & 63) >> 1)))
#define SET(n) (prime[n >> 6] |= (1 << ((n & 63) >> 1)))

void sieve() {
	int root = sqrt(SIZE);

	for(int i = 3; i <= root; i += 2) {
		if(CHECK(i) == false) {
			for(int j = i * i; j < SIZE; j += i << 1) {
				SET(j);
			}
		}
	}
}

bool isPrime(int n) {
	return n > 1 && (n == 2 || ((n & 1) && !CHECK(n)));
}

int main()
{
	sieve();
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