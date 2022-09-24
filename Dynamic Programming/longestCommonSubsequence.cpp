/**
 *  Name: Longest Common Subsequence
 *  Author Name: Sourab Hossain
 */

#include "bits/stdc++.h"

using namespace std;

#define SIZE 10001

int dp[SIZE][SIZE];

int lcs(string word1, string word2, int m, int n) {
    if(m == 0 || n == 0) {
        return 0;
    }

    if(dp[m][n] > 0) {
        return dp[m][n];
    }

    if(word1[m - 1] == word2[n - 1]) {
        dp[m][n] = 1 + lcs(word1, word2, m - 1, n - 1);
    } else {
       dp[m][n] = max(lcs(word1, word2, m, n - 1), lcs(word1, word2, m - 1, n));
    }

    return dp[m][n];
}

int longestCommonSubsequence(string str1, string str2) {
    int m = str1.size(), n = str2.size();
    int dp[m + 1][n + 1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
	    if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(str1[i - 1] == str2[j - 1]) {
		dp[i][j] = dp[i - 1][j - 1] + 1;
	    } else {
		dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
	    }
	}
     }

    return dp[m][n];
}

int main(int argc, char const *argv[])
{
	string text1 = "abcde", text2 = "ace";
	
	cout << longestCommonSubsequence(text1, text2) << endl;

	return 0;
}
