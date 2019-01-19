/**
  *  Name: Digits in N Factorial
  *  Author Name: Sourav Hossain
  */

#include <bits/stdc++.h>

using namespace std;

int digitCount(int n) {
	if(n == 0) {
		return 1;
	}

	double count = 0;

	for(int i = 1; i <= n; i++) {
		count += log10(i);
	}

	return (int)floor(count) + 1;
}

int main(int argc, char const *argv[])
 {
 	int n;

 	scanf("%d", &n);
 	printf("%d\n", digitCount(n));

 	return 0;
 } 