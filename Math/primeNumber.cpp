/**
 * Name: Prime Number
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 100000002

bool prime[SIZE];

void sieve() {
	int root = sqrt(SIZE);
	
	for(int i = 3; i <= root; i += 2) {
        if(prime[i] == false) {
            for(int j = i * i; j < SIZE; j += i << 1) {
                prime[j] = 1;
            }
        }
	}
}  

bool isPrime(int n) {
	if(n < 2) {
		return false;
	}

	if(n == 2) {
		return true;
	}

	if(n & 1) {
		return prime[n] == false;
	}

	return false;
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