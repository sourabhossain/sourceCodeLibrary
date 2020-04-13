/**
 *  Name: Adjacency List
 *  Author Name: Sourab Hossain
 */
#include <bits/stdc++.h>
#define SIZE 100001  

using namespace std;

vector<int> g[SIZE];

int main(int argc, char const *argv[])
{
	int node, edge, u, v;

	scanf("%d%d", &node, &edge);

	for(int i = 0; i < edge; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i = 1; i <= node; i++) {
		printf("%d = ", i);

		for(int j = 0; j < g[i].size(); j++) {
			printf("%d ", g[i][j]);
		}
		putchar('\n');
	}
	
	return 0;
}