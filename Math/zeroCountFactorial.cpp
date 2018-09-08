/**
 *  Name: Zero Count Factorial
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, zero = 0;

    scanf("%d", &n);

    while(n) {
    	zero += n /= 5;
    }

    printf("%d\n", zero);

	return 0;
}