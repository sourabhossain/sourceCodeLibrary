/**
 *  Name: Coins
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 5;
long long dp[N];
vector<long long> coins;

long long getNumberOfWays(int taka) {
    if(taka == 0) {
        return 1;
    }

    if(taka < 0) {
        return 0;
    }

    if(dp[taka] != -1) {
        return dp[taka];
    }

    dp[taka] = 0;

    for(int item : coins) {
        dp[taka] += getNumberOfWays(taka - item);
    }

    return dp[taka];
}

int main(int argc, char const *argv[])
{
    int T, n, taka;
    memset(dp, -1, N * sizeof(long long));

    scanf("%d%d", &T, &taka);

    while(T--) {
        scanf("%d", &n);
        coins.push_back(n);
    }

    printf("%lld\n", getNumberOfWays(taka));

    return 0;
}
