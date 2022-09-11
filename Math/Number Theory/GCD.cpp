/**
 * Name: GCD
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int gcd(int m, int n) {
    int minValue = min(m, n);
    
    if(m % minValue == 0 && n % minValue == 0) {
        return minValue;
    }
    
    for(int i = minValue / 2; i >= 2; i--) {
        if(m % i == 0 && n % i == 0) {
            return i;
        }
    }
    
    return 1;
}

int gcd(int m, int n) {
    if(m == 0) {
        return n;
    }
    
    if(n == 0) {
        return m;
    }
    
    if(m == n) {
        return m;
    }
    
    if(m > n) {
        return gcd(m - n, n);
    }
    
    return gcd(m, n - m);
}

int gcd(int first, int second) {
	int temp;

	while(second) {
		temp = first % second;
		first = second;
		second = temp;
	}

	return first;
}

int gcd(int m, int n) {
    while(m != n) {
        if(m > n) {
            m = m - n;
        } else {
            n = n - m;
        }
    }
    
    return m;
}

int main()
{
	int first, second;
	
	scanf("%d%d", &first, &second);
	printf("%d\n", gcd(second, first - second));
	
	return 0;
}
