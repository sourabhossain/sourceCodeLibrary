/**
 *  Name: Print All Sub Set
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void printSubSet(vector<string>& subString, string& str, int length) {
	int possibleSubSet = 1 << length;

	for(int i = 0; i < possibleSubSet; i++) {
		string temp = "";

		for(int j = 0; j < length; j++) {
			if(i & (1 << j)) {
				temp += str[j];
			}
		}

		subString.push_back(temp);
	}
}

int main()
{
	string str;
	vector<string> subString;

	cin >> str;
	sort(str.begin(), str.end());
	printSubSet(subString, str, str.size());

	for(int i = 0, length = subString.size(); i < length; i++) {
		cout << subString[i] << endl;
	}

	return 0;
}