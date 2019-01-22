/**
 *  Name: Is Prime    
 *  Author Name: Sourav Hossain 
 */

#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
	if(n < 2) {
		return false;
	}

	if(n < 4) {
		return true;
	}

	if(n % 2 == 0 || n % 3 == 0) {
		return false;
	}
    
    int root = sqrt(n);

	for(int i = 5; i <= root; i += 6) {
		if(n % i == 0 || n % (i + 2) == 0) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	int n;

	while(scanf("%d", &n) != EOF) {
		(isPrime(n))? puts("YES") : puts("NO");
	}

	return 0;
}