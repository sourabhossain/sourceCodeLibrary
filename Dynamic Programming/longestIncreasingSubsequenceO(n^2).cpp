/**
 *  Name: Longest Increasing Subsequence O(n^2)
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int longestIncreasingSubsequence(vector<int>& sequence, int n) {
	vector<int> dp(n, 1); 
	int result = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(sequence[j] < sequence[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		result = max(result, dp[i]);
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);
	vector<int> sequence(n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &sequence[i]);
	}

	printf("%d\n", longestIncreasingSubsequence(sequence, n));

	return 0;
}