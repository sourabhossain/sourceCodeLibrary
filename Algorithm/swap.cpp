/**
 *  Name: Swap Two Value
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

void swap(int *a, int *b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int main()
{
	int a, b;

	scanf("%d%d", &a, &b);
	swap(&a, &b);
	printf("%d %d\n", a, b);

	return 0;
}
