/**
 *  Name: Segment Tree
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

#define SIZE 100001
#define LEFT(n) (n << 1)
#define RIGHT(n) ((n << 1) + 1)
#define MID(start, end) (start + ((end - start) >> 1))

using namespace std;

int inputArray[SIZE], segmentTree[SIZE * 3];

void buildTree(int node, int start, int end) {
	if (start == end) {
		segmentTree[node] = inputArray[start];
		return;
	}

	int leftChild = LEFT(node);
	int rightChild = RIGHT(node);
	int mid = MID(start, end);

	buildTree(leftChild, start, mid);
	buildTree(rightChild, mid + 1, end);
	segmentTree[node] = segmentTree[leftChild] + segmentTree[rightChild];
}

int rangeQuery(int node, int start, int end, int queryStart, int queryEnd) {
	if (queryStart > end || queryEnd < start) {
		return 0;
	}

	if (start >= queryStart && end <= queryEnd) {
		return segmentTree[node];
	}

	int leftChild = LEFT(node);
	int rightChild = RIGHT(node);
	int mid = MID(start, end);

	return rangeQuery(leftChild, start, mid, queryStart, queryEnd) + rangeQuery(rightChild, mid + 1, end, queryStart, queryEnd);
}

void updateTree(int node, int start, int end, int updateIndex, int newValue) {
	if (updateIndex > end || updateIndex < start) {
		return;
	}

	if (start == end) {
		segmentTree[node] = newValue;
		return;
	}

	int leftChild = LEFT(node);
	int rightChild = RIGHT(node);
	int mid = MID(start, end);

	updateTree(leftChild, start, mid, updateIndex, newValue);
	updateTree(rightChild, mid + 1, end, updateIndex, newValue);
	segmentTree[node] = segmentTree[leftChild] + segmentTree[rightChild];
}

int main()
{
	int arraySize;
	cin >> arraySize;

	for (int i = 1; i <= arraySize; i++) {
		cin >> inputArray[i];
	}

	buildTree(1, 1, arraySize);

	cout << rangeQuery(1, 1, arraySize, 1, 5) << endl;
	cout << rangeQuery(1, 1, arraySize, 2, 3) << endl;

	updateTree(1, 1, arraySize, 2, 0);
	cout << rangeQuery(1, 1, arraySize, 1, 5) << endl;

	updateTree(1, 1, arraySize, 2, 2);
	cout << rangeQuery(1, 1, arraySize, 1, 5) << endl;

	return 0;
}
