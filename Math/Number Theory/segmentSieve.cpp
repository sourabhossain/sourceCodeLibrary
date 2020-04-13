/**
 *  Name: Segment Sieve 
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

#define SIZE 10000002

int prime[(SIZE >> 6) + 2];

#define CHECK(n) (prime[n >> 6] & (1 << ((n % 64) >> 1)))
#define SET(n) (prime[n >> 6] |= (1 << ((n % 64) >> 1)))

vector<int> sievePrime;

void sieve() {
	int root = sqrt(SIZE);
	sievePrime.push_back(2);

	for(int i = 3; i < SIZE; i += 2) {
		if(CHECK(i) == false) {
			sievePrime.push_back(i);

			if(i <= root) {
				for(int j = i * i; j < SIZE; j += i << 1) {
					SET(j);
				}
			}
		}
	}
}

vector<long long> segmentPrime;

void segmentSieve(long long low, long long high) {
	bool segment[high - low + 1] = {0};
	int root = sqrt(high) + 1;
	long long start, temp;

	if(low == 0) {
		segment[0] = segment[1] = 1;
	} else if(low == 1) {
		segment[0] = 1;
	}

	for(int i = 0; sievePrime[i] <= root; i++) {
		temp = sievePrime[i];
		start = temp * temp;

		if(start < low) {
			start = ((low + temp - 1) / temp) * temp;
		}

		for(long long j = start; j <= high; j += temp) {
			segment[j - low] = 1;
		}
	}

	for(long long i = low; i <= high; i++) {
		if(segment[i - low] == 0) {
			segmentPrime.push_back(i);
		}
	}
}

int main()
{
	sieve();
	long long low, high;

	cin >> low >> high;

	segmentPrime.clear();
	segmentSieve(low, high);

	for(int i = 0, length = segmentPrime.size(); i < length; i++) {
		cout << segmentPrime[i] << " ";
	}
	cout << endl;

	return 0;
}