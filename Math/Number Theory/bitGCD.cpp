/**
  *  Name: Bit GCD 
  *  Author Name: Sourab Hossain
  */

#include <bits/stdc++.h>

using namespace std;

/**
int gcd(int a, int b) {
	while(b) {
		a %= b;
		b ^= a;
		a ^= b;
		b ^= a;
	}
	
	return a;
}*/

int gcd(int a, int b) {
    while(b) {
		b ^= a ^= b ^= a %= b;
	}
	
	return a;
}

int main()
{
    int a, b;

    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b)); 	
     
    return 0;
}