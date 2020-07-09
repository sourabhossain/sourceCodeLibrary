/**
 * Name: GCD
 * Author Name: Sourab Hossain
 */

#include <stdio.h>

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