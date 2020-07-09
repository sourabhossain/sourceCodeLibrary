/**
 *	Name: N Number LCM
 *	Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

int gcd(int first, int second)
{

	while(second) {
		second ^= first ^= second ^= first %= second;
	}

	return first;
}

int n_lcm(int *data, int n)
{
	int lcm = data[0];

	for (int i = 1; i < n; i++)
	{
		lcm = (lcm / gcd(lcm, data[i])) * data[i];
	}

	return lcm;
}

int main()
{
	int n;

	scanf("%d", &n);
	int data[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	printf("%d\n", n_lcm(data, n));

	return 0;
}