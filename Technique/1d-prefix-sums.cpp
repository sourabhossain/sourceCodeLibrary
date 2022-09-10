#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    long long data[n], dp[n + 1] = {0};

    for(long long& x : data) {
        cin >> x;
    }

    /**
    for(int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] + data[i];
    }
    */

    partial_sum(data, data + n, dp + 1);

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l] << endl;
    }

    return 0;
}
