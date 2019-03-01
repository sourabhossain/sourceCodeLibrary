/**
 *  Name: Pascal Triangle
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 51

using namespace std;

vector<vector<unsigned long long> > pascal;

void pascalTriangle() {
	for(int i = 0; i < SIZE; i++) {
        vector<unsigned long long> dp(i + 1);
		dp[0] = dp[i] = 1;

		for(int j = 1; j < i; j++) {
			dp[j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}

		pascal.push_back(dp);
	}
}

int main(int argc, char const *argv[])
{
	pascalTriangle();
	int n;

	scanf("%d", &n);

    for(int i = 0; i < n; i++) {
    	printf("%llu ", pascal[n - 1][i]);

    	if(i == n - 1) {
    		printf("\n");
    	}
    }

	return 0;
}