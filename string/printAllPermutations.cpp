/**
 *  Name: Print All Permutations 
 *  Author Name: Sourab Hossain 
 */

#include <bits/stdc++.h>

using namespace std;

void permutation(string str, int length) {
	sort(str.begin(), str.end());
    --length;

	while(true) {
		cout << str << endl;
		int i = length;

		while(str[i - 1] >= str[i]) {
			if(--i == 0) {
				return;
			}
		}

		int j = length;

		while(j > i && str[j] <= str[i - 1]) {
			j--;
		}

		swap(str[i - 1], str[j]);
		reverse(str.begin() + i, str.end());
	}
}

void permutation(string str, int index, int length) {
	if(index + 1 == length) {
		cout << str << endl;
		return;
	}

	for(int i = index; i < length; i++) {
		swap(str[index], str[i]);
		permutation(str, index + 1, length);
		swap(str[index], str[i]);
	}
}

int main()
{
	string str;

	cin >> str;
	permutation(str, 0, str.size());

	return 0;
}