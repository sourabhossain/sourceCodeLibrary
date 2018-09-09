/**
 *  Name: Big Number Division
 *  Author Name: Sourav Hossain
 */ 

#include <bits/stdc++.h>

using namespace std;

string bigDivision(string n, long long d) {
	if(d == 0) {
		return "-1";
	}

	string ans = "";
	int index = 0;
	long long temp = n[index] - '0';
    
    while(n[index] && temp < d) {
    	temp = temp * 10 + (n[++index] - '0');
    }

    while(n[index]) {
    	ans += (temp / d) + '0';
    	temp = (temp % d) * 10 + (n[++index] - '0');
    }

	return (ans.size())? ans : "0";
}

int main()
{
	string n;
	long long d;

	cin >> n >> d;
	cout << bigDivision(n, d) << endl;

	return 0;
}