/**
 * Name: String Palindrome
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

bool isPalindrome(char *string) {
	int length = strlen(string), i;

	for(i = 0; i < length; i++) {
		if(string[i] != string[--length]) {
			return false;
		}	
	}

	return true;
}

int main()
{
	char string[101];
    
	scanf("%s", string);

	if(isPalindrome(string)) {
		puts("Yes");
	} else {
		puts("No");
	}

	return 0;
}