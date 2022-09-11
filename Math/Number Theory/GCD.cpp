/**
 * Name: GCD
 * Author Name: Sourab Hossain
 */

#include <stdio.h>

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

int gcd(int first, int second) {
	int temp;

	while(second) {
		temp = first % second;
		first = second;
		second = temp;
	}

	return first;
} 

int main()
{
	int first, second;
	
	scanf("%d%d", &first, &second);
	printf("%d\n", gcd(second, first - second));
	
	return 0;
}
