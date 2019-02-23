/**
 *  Name: Merge Sort
 *  Autor Name: Sourav Hossain
 */

#include <bits/stdc++.h> 

using namespace std;

void merge(int left, int mid, int right, vector<int>& data) {
	list<int> temp;
	int firstIndex = left, secondIndex = mid + 1;

	while(firstIndex <= mid && secondIndex <= right) {
		if(data[firstIndex] < data[secondIndex]) {
			temp.push_back(data[firstIndex++]);
		} else {
			temp.push_back(data[secondIndex++]);
		}
	}

	while(firstIndex <= mid) {
		temp.push_back(data[firstIndex++]);
	}

	while(secondIndex <= right) {
		temp.push_back(data[secondIndex++]);
	}

	for(int i = left; i <= right; i++) {
		data[i] = temp.front();
		temp.pop_front();
	}
}

void mergeSort(int left, int right, vector<int>& data) {
	if(left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(left, mid, data);
		mergeSort(mid + 1, right, data);
		merge(left, mid, right, data);
	}
}

int main()
{
	int n;

	scanf("%d", &n);
	vector<int> data(n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	mergeSort(0, n - 1, data);

	for(int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	putchar('\n');

	return 0;
}
