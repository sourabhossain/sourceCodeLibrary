/**
 *  Name: Print All Combinatoric
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void printAllCombinatoric(string& str, string result, int n, int k) {
	if(k == 0) {
		cout << result << endl;
		return;
	}	

	for(int i = 0; i < n; i++) {
		printAllCombinatoric(str, result + str[i], n, k - 1);
	}
}

int main()
{
	string str;
	int k;

	cin >> str >> k;
	printAllCombinatoric(str, "", str.size(), k);

	return 0;
}