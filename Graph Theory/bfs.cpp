/**
 *  Name: Breadth First Search (BFS)
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void bfs(int node, vector<vector<int> >& g, int source) {
	bool visited[node + 1];
	int distance[node + 1];
	queue<int> q;
    
    memset(visited, 0, sizeof(visited));
    memset(distance, -1, sizeof(distance));

	q.push(source);
	visited[source] = 1;
	distance[source] = 0;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(int i = 0, length = g[u].size(); i < length; i++) {
			int v = g[u][i];

			if(!visited[v]) {
				visited[v] = 1;
				q.push(v);
				distance[v] = distance[u] + 1;
			}
		}
	}

	for(int i = 1; i <= node; i++) {
		cout << source << " --> " << i << " --> " << distance[i] << endl;
	}
}

int main()
{
	int node, edges, source;

	cin >> node >> edges;
	vector<vector<int> > g(node + 1);

	for(int i = 0, u, v; i < edges; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	cin >> source;

	bfs(node, g, source);

	return 0;
}
