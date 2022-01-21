/** 
 * Name: Maximum Sum Sub-Array
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int maximumSumSubarray(int *data, int n)
{
    int minPrefixSum = 0;
    int result = INT_MIN;
    int prefixSum[n];

    prefixSum[0] = data[0];

    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + data[i];
    }

    for(int i = 0; i < n; i++) {
        result = max(result, prefixSum[i] - minPrefixSum);
        minPrefixSum = min(minPrefixSum, prefixSum[i]);
    }

    return result;
}

int main()
{
    int n;

    scanf("%d", &n);
    int data[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    printf("%d\n", maximumSumSubarray(data, n));

    return 0;
}
