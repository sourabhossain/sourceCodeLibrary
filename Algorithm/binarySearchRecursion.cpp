/**
  *  Name: Binary Search Recursion 
  *  Author Name: Sourav Hossain
  */

#include <bits/stdc++.h>

using namespace std;

int binarySearch(int left, int right, int key, vector<int>& data) {
	if(left > right) {
		return -1;
	}

	int mid = left + (right - left) / 2;

	if(data[mid] == key) {
		return mid;
	}

	if(data[mid] < key) {
		return binarySearch(mid + 1, right, key, data);
	}

	return binarySearch(left, mid - 1, key, data);
}

int main()
{ 
	int n, key;

	scanf("%d%d", &n, &key);
	vector<int> data(n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	} 

	printf("Index: %d\n", binarySearch(0, n, key, data));
   
	return 0;
}