/**
 *  Name: Power Recursion
 *  Author Name: Sourab Hossain
 *  Gmail: cpsourab@gmail.com 
 */

#include <bits/stdc++.h>

using namespace std;

int power(int n, int p) {
    if(p < 1) {
        return 1;
    }

    if(p & 1) {
        return n * power(n * n, p >> 1);
    }

    return power(n * n, p >> 1);
}

int main()
{
	int n, p;

	scanf("%d%d", &n, &p);
	printf("%d\n", power(n, p));

	return 0;
}