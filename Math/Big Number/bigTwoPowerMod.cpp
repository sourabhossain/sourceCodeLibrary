/**
 *  Name: Big Two Power Mod
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int bigMod(int b, int p, int m) {
	if(p == 1) {
		return b & m; 
	}

	int mod = bigMod(b, p / 2, m) & m;
	mod = ((mod & m) * (mod & m)) & m;

	if(p & 1) {
		mod = ((mod & m) * (b & m)) & m;
	}

	return mod;
}

int main()
{
	int b, p, m;

	cin >> b >> p >> m;
	cout << bigMod(b, p, m - 1) << endl;

	return 0;
}