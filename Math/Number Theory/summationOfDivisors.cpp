/**
 * Name: Summation of Divisors
 * Author Name: Sourav Hossain
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

long long power(long long b, int p) {
    long long result = 1;

    while(p) {
        if(p & 1) {
            result *= b;
        }

        p >>= 1;
        b *= b;
    }

    return result;
}

long long summationOfDivisors(long long n) {
    map<long long, int> m;
    int root = sqrt(n);

    for(int i = 0, length = prime.size(); i < length && prime[i] <= root; i++) {
        while(n % prime[i] == 0) {
            m[prime[i]]++;
            n /= prime[i];
        }
    }

    if(n > 1) {
        m[n]++;
    }

    long long result = 1, i = 0;

    for(map<long long, int>::iterator it = m.begin(); it != m.end(); it++) {
        result *= (power(it->first, it->second + 1) - 1) / (1 << i++);
    }

    return result;
}

int main()
{
    sieve();
    long long n;

    while(scanf("%lld", &n) != EOF) {
        cout << summationOfDivisors(n) << endl;
    }

    return 0;
}