/**
 *  Name: Depth First Search (DFS)
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 100001
#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

vector<int> G[SIZE];
int dfsTime, color[SIZE], d[SIZE], f[SIZE];

void dfs(int u) {
	d[u] = ++dfsTime;
	color[u] = GREY;

	for(int i = 0, length = G[u].size(); i < length; i++) {
		int v = G[u][i];

		if(color[v] == WHITE) {
			dfs(v);
		}
	}

	color[u] = BLACK;
	f[u] = ++dfsTime;
}

int main(int argc, char const *argv[])
{
	int node, edges;

    cin >> node >> edges;

	for(int i = 0, u, v; i < edges; i++) {
		cin >> u >> v;
		G[u].push_back(v);
	}

	for(int i = 1; i <= node; i++) {
		if(color[i] == WHITE) {
			dfs(i);
		}
	}

	for(int i = 1; i <= node; i++) {
		cout << i << " --> " << d[i] << " --> " << f[i] << endl;
	}

	return 0;
}