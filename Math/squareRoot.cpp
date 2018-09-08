/**
 * Name: Square root
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define MINIMUM_RANG 0.000001 

double square(double n) {
    if(n < 0) {
		puts("Error! Invalid Input!");
		exit(1);
	}

	double root = n, temp = 1;

	while((root - temp) > MINIMUM_RANG) {
		root = (root + temp) / 2;
		temp = n / root;
	}

	return root;
} // end square function

int main()
{
	double n;
    
	printf("Input: ");
	scanf("%lf", &n);
	printf("Output: %lf\n", square(n)); // go to square function 

	return 0;
}