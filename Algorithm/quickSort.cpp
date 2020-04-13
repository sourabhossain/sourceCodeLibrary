/**
 *  Name: Quick Sort
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int partition(int left, int right, vector<int>& data) {
	int pivot = data[right], partitionIndex = left;

	for(int i = left; i < right; i++) {
		if(data[i] < pivot) {
			swap(data[partitionIndex++], data[i]);
		}
	}

	swap(data[partitionIndex], data[right]);
	return partitionIndex;
}

void quickSort(int left, int right, vector<int>& data) {
	if(left < right) {
		int partitionIndex = partition(left, right, data);
		quickSort(left, partitionIndex - 1, data);
		quickSort(partitionIndex + 1, right, data);
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

	quickSort(0, n, data);

	for(int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	putchar('\n');

	return 0;
}