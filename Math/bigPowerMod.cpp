/**
 *  Name: Big Power Mod
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int bigMod(int n, int p, int m) {
	if(p == 0) {
		return 1 % m;
	}

	int mod = bigMod(n, p / 2, m);
	mod = ((mod % m) * (mod % m)) % m;

	if(p & 1) {
		mod = ((n % m) * (mod % m)) % m;
	}

	return mod;
}

int main()
{
	int n, p, m;

	scanf("%d%d%d", &n, &p, &m);
	printf("%d\n", bigMod(n, p, m));

	return 0;
}