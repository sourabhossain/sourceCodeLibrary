/** 
 * Name: Prefix Sum
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int data[N];
int dp[N];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &data[i]);

        if (i == 0) {
            dp[i] = data[i];
        } else {
            dp[i] = dp[i-1] + data[i];
        }
    }

    int q;
    scanf("%d", &q);

    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);

        if(r > n || l < 1) {
            break;
        }

        if(l == 1) {
            printf("%d\n", dp[r]);
        } else {
            printf("%d\n", dp[r] - dp[l-1]);
        }
    }

    return 0;
}
