/**
 *  Name: Print All Permutations 
 *  Author Name: Sourav Hossain 
 */

#include <bits/stdc++.h>

using namespace std;

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