/**
 *  Name: Adjacency Matrix
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int matrix[101][101];

int main(int argc, char const *argv[])
{
	int node, edge, x, y;

	scanf("%d%d", &node, &edge);

	for(int i = 0; i < edge; i++) {
		scanf("%d%d", &x, &y);
		matrix[x][y] = 1;
		matrix[y][x] = 1;
	}

	for(int i = 1; i <= node; i++) {
		for(int j = 1; j <= node; j++) {
			printf("%d ", matrix[i][j]);
		}
		putchar('\n');
	}
	
	return 0;
}