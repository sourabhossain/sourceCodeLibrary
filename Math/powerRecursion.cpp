/**
 *  Name: Power Recursion
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int power(int n, int p) {
    if(p == 0) {
    	return 1;
    }	

    if(p == 1) {
    	return n;
    }
    
    int temp = power(n, p / 2);
    temp *= temp;

    if(p & 1) {
        temp *= n;
    }

    return temp;
}  

int main()
{
	int n, p;

	scanf("%d%d", &n, &p);
	printf("%d\n", power(n, p));

	return 0;
}