/**
 *  Name: Combination
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

long long table[51][51];

long long nCr(int n, int r) {
	if(r == 1) {
		return n;
	}

	if(n == r) {
		return 1;
	}

	if(table[n][r] != -1) {
		return table[n][r];
	}

	table[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
	return table[n][r];
}

int main(int argc, char const *argv[])
{
	memset(table, -1, sizeof(table));
	int n, r;

	scanf("%d%d", &n, &r);
	printf("%lld\n", nCr(n, r));

	return 0;
}