/**
 *  Name: Sub Set
 *  Author Name: Sourav Hossain 
 */

#include <bits/stdc++.h>

using namespace std;

void printSubSet(vector<int>& data, int length) {
	int possibleSubSet = 1 << length;

	for(int i = 0; i < possibleSubSet; i++) {
		for(int j = 0; j < length; j++) {
			if(i & (1 << j)) {
				cout << data[j] << " ";
			}
		}
		cout << endl;
	}
}

int main()
{
	int length;

	cin >> length;
	vector<int> data(length);

	for(int i = 0; i < length; i++) {
		cin >> data[i];
	}

	sort(data.begin(), data.end());
	printSubSet(data, length);

	return 0;
}