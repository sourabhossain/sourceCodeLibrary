/**
 *  Name: marge Sort Tree (MST) 
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

#define SIZE 100001
#define LEFT(n) ((n << 1) + 1)
#define RIGHT(n) ((n << 1) + 2)
#define MID(left, right) (left + ((right - left) >> 1))

vector<int> segment[SIZE << 2];
int n, data[SIZE];

void build(int node, int s, int e) {
	if(s == e) {
		segment[node].push_back(data[s]);
		return;
	}

	build(LEFT(node), s, MID(s, e));
	build(RIGHT(node), MID(s, e) + 1, e);
	merge(segment[LEFT(node)].begin(), segment[LEFT(node)].end(), segment[RIGHT(node)].begin(), segment[RIGHT(node)].end(), back_inserter(segment[node]));
}

int query(int node, int s, int e, int l, int r, int k) {
	if(r < s || e < l) {
		return -1;
	}

	if(l <= s && e <= r) {
		auto num = lower_bound(segment[node].begin(), segment[node].end(), k + 1);
		return (num != segment[node].end())? *num : -1;
	}

	return max(query(LEFT(node), s, MID(s, e), l, r, k), query(RIGHT(node), MID(s, e) + 1, e, l, r, k));
}

int main(int argc, char const *argv[])
{
	int n, q;

	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &data[i]);
	}

	build(0, 1, n);

	while(q--) {
		int l, r, k, ans = -1;

		scanf("%d%d%d", &l, &r, &k);

		while(r >= l) {
			if(query(0, 1, n, l, MID(l, r), k) == -1) {
				l = MID(l, r) + 1;
			} else {
				ans = MID(l, r);
				r = ans - 1;
			}
		}

		printf("%d\n", ans);
	}
	
	return 0;
}