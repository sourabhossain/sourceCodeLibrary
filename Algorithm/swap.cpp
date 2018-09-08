/**
 *  Name: Swap Two Value
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

void swap(int *a, int *b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
} // end swap function

int main()
{
	int a, b;

	scanf("%d%d", &a, &b);
	swap(&a, &b); // go to swap function
	printf("%d %d\n", a, b);

	return 0;
}
