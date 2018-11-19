/**
 *  Name: Count Divisors
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 100000002

using namespace std;

int isPrime[(SIZE >> 6) + 2];
vector<int> prime;

#define CHECK(n) (isPrime[n >> 6] & (1 << ((n & 63) >> 1)))
#define SET(n) (isPrime[n >> 6] |= (1 << ((n & 63) >> 1)))

void sieve() {
	int root = sqrt(SIZE);
	prime.push_back(2);

	for(int i = 3; i < SIZE; i += 2) {
		if(CHECK(i) == false) {
			prime.push_back(i);
            
            if(i <= root) {
				for(int j = i * i; j < SIZE; j += i << 1) {
					SET(j);
				}
			}
		}
	}
}

int countDivisors(long long n) {
	int divisor = 1, root = sqrt(n);

	for(int i = 0, length = prime.size(); i < length && prime[i] <= root; i++) {
		if(n % prime[i] == 0) {
			int count = 1;

			while(n % prime[i] == 0) {
				n /= prime[i];
				count++;
			}

			divisor *= count;
		}
	}

	return divisor;
}

int main()
{
	sieve();
	long long n;

	while(scanf("%lld", &n) != EOF) {
		printf("%d\n", countDivisors(n));
	}

	return 0;
}