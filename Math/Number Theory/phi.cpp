/**
 *  Name: PHI
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int phi(int n) { 
	int total = n, root = sqrt(n);

	for(int i = 2; i <= root; i++) {
		if(n % i == 0) {
			while(n % i == 0) {
				n /= i;
			}

			total -= total / i;
		}
	}

	if(n > 1) {
		total -= total / n;
	}

	return total;
}  

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", phi(n));

	return 0;
}