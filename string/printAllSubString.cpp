/**
 *  Name: Print All Sub String
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void subString(string str, int length) {
	set<string> s;

	for(int i = 1; i <= length; i++) {
		for(int j = 0; j <= length - i; j++) {
			int n = j + i - 1;
			string temp = "";

			for(int k = j; k <= n; k++) {
				temp += str[k];
			}
			
			s.insert(temp);
		}
	}

	for(set<string>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
}

int main()
{
	string str;

	cin >> str;
	subString(str, str.size());

	return 0;
}