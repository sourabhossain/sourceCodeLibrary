/**
 *  Name: Zero Count Factorial
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int zeroCount(int n) {
	int zero = 0;

	while(n) {
    	zero += n /= 5;
    }
    
    return zero;
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", zeroCount(n));

	return 0;
}