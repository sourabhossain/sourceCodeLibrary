/**
 *  Name: String Palindrome
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

bool palindrome(string s) {
    for(int i = 0, length = s.size(); i < length; i++) {
    	if(s[i] != s[--length]) {
    		return false;
    	}
    }	

    return true;
}

int main()
{
	string s;

	cin >> s;

	if(palindrome(s)) {
		puts("Yes");
	} else {
		puts("No");
	}

	return 0;
}