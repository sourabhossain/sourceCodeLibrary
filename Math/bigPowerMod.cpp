/**
 *  Name: Big Power Mod
 *  Author Name: Sourav Hossain 
 */

#include <bits/stdc++.h>

using namespace std;

int bigMod(int b, int p, int m) {
    int result = 1;
    
    while(p) {
    	if(p & 1) {
    		result = ((result % m) * (b % m)) % m;
    	}

    	p >>= 1;
    	b = ((b % m) * (b % m)) % m;
    }

    return result;	
}

int main()
{
	int b, p, m;

	cin >> b >> p >> m;
	cout << bigMod(b, p, m) << endl;

	return 0;
}