/**
 *  Name: Ternary Search Recursion
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int ternarySearch(int left, int right, int key, vector<int>& data) {
	if(left > right) {
		return -1;
	}

	int firstMid = left + (right - left) / 3;
	int secondMid = right - (right - left) / 3;

	if(data[firstMid] == key) {
		return firstMid;
	}

	if(data[secondMid] == key) {
		return secondMid;
	}

	if(data[firstMid] > key) {
		return ternarySearch(left, firstMid - 1, key, data);
	}

	if(data[secondMid] < key) {
		return ternarySearch(secondMid + 1, right, key, data);
	}
	
	return ternarySearch(firstMid + 1, secondMid - 1, key, data);	
}

int main()
{   
	int n, key;

	scanf("%d%d", &n, &key);
	vector<int> data(n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	printf("%d\n", ternarySearch(0, n, key, data));

	return 0;
}