/**
 * Name: Square root
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>
#define MINIMUM_RANG 0.000001 

double square(double n) {
    if(n < 0) {
    	return -1;
	}

	double root = n, temp = 1;

	while((root - temp) > MINIMUM_RANG) {
		root = (root + temp) / 2;
		temp = n / root;
	}

	return root;
}

int main()
{
	double n;
    
	scanf("%lf", &n);
	printf("%lf\n", square(n)); 

	return 0;
}