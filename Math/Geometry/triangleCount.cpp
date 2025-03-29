/**
 *  Name: Triangle Count
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);
	printf("%d\n", (n * (n + 2) * ((n << 1) + 1)) >> 3);

	return 0;
}