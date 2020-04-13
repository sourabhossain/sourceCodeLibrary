/**
 *  Name: Longest Increasing Subsequence O(n log(n))
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int longestIncreasingSubsequence(vector<int>& sequence, int n) {
    vector<int> dp;

    dp.push_back(sequence[0]);

    for(int i = 1; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), sequence[i]);

        if(it != dp.end()) {
            *it = sequence[i];
        } else {
            dp.push_back(sequence[i]);
        }
    }

    return dp.size();
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