/**
 *  Name: Ternary Search
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int ternarySearch(vector<int>& data, int key) {
	int left = 0, right = data.size();
	int firstMid, secondMid;

	while(left <= right) {
		firstMid = left + (right - left) / 3;
		secondMid = right - (right - left) / 3;

		if(data[firstMid] == key) {
			return firstMid;
		}

		if(data[secondMid] == key) {
			return secondMid;
		}

		if(data[firstMid] > key) {
			right = firstMid - 1; 
		} else if(data[secondMid] < key) {
			left = secondMid + 1;
		} else {
			left = firstMid + 1;
			right = secondMid - 1;
		}
	}

	return -1;
}

int main()
{   
	int n, key;

	scanf("%d%d", &n, &key);
	vector<int> data(n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	printf("%d\n", ternarySearch(data, key));

	return 0;
}