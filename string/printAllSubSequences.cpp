/**
 *  Name: Print All Sub Sequences
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void printSubSequences(set<string>& subSequences, string& str, int length) {
	int possibleSubSequences = 1 << length;

	for(int i = 0; i < possibleSubSequences; i++) {
		string temp = "";

		for(int j = 0; j < length; j++) {
			if(i & (1 << j)) {
				temp += str[j];
			}
 		}

 		subSequences.insert(temp);
	} 
}

int main()
{
	string str;
	set<string> subSequences;

	cin >> str;
	printSubSequences(subSequences, str, str.size());

	for(set<string>::iterator it = subSequences.begin(); it != subSequences.end(); it++) {
		cout << *it << endl; 
	}

	return 0;
}