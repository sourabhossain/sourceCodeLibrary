#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long data[n];

    for(long long& x : data) {
        cin >> x;
    }

    long long currentSum = data[0];
    long long maxSubArraySum = data[0];

    for(int i = 1; i < n; i++) {
        currentSum = max(currentSum + data[i], data[i]);
        maxSubArraySum = max(maxSubArraySum, currentSum);
    }

    cout << maxSubArraySum << endl;

    return 0;
}
