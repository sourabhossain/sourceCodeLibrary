/**
  *  Name: Big Number Mod 
  *  Author Name: Sourav Hossain
  */

#include <bits/stdc++.h>

using namespace std;

long long bigMod(string n, long long m) {
	long long mod = 0;

	for(int i = 0; n[i]; i++) {
		mod = (mod * 10 + n[i] - '0') % m;
	}

	return mod;
} // end bigMod function 

int main()
{
	string n;
	long long m;

	cin >> n >> m;
	cout << bigMod(n, m) << endl; // go to bigMod function 

	return 0;
}