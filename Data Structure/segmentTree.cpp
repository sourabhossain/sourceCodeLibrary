/**
 *  Name: Segment Tree
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 100001
#define LEFT(n) (n << 1)
#define RIGHT(n) ((n << 1) + 1)
#define MID(left, right) (left + ((right - left) >> 1))

using namespace std;

int arr[SIZE], tree[SIZE * 3];

void init(int node, int b, int e) {
	if(b == e) {
		tree[node] = arr[b];
		return;
	}

	init(LEFT(node), b, MID(b, e));
	init(RIGHT(node), MID(b, e) + 1, e);
	tree[node] = tree[LEFT(node)] + tree[RIGHT(node)];
}

int query(int node, int b, int e, int i, int j) {
	if(i > e || j < b) {
		return 0;
	}

	if(b >= i && e <= j) {
		return tree[node];
	}

	return query(LEFT(node), b, MID(b, e), i, j) + query(RIGHT(node), MID(b, e) + 1, e, i, j);	
}

void update(int node, int b, int e, int i, int value) {
	if(i > e || i < b) {
		return;
	}

	if(b >= i && e <= i) {
		tree[node] = value;
		return;
	}

	update(LEFT(node), b, MID(b, e), i, value);
	update(RIGHT(node), MID(b, e), e, i, value);
	tree[node] = tree[LEFT(node)] + tree[RIGHT(node)];
}

int main(int argc, char const *argv[])
{
	int n;

	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	init(1, 1, n);
	// update(1, 1, n, 2, 0);
	// update(1, 1, n, 2, 2);
   
   cout << query(1, 1, n, 1, 5) << endl; 
   cout << query(1, 1, n, 2, 3) << endl; 
	
	return 0;
}