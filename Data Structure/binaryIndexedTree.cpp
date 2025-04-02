/**
 *  Name: Binary Indexed Tree
 *  Author Name: Sourab Hossain
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mx 10000

int ar[mx], tree[mx];

int read(int idx) {
    int sum = 0;

    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

void update(int idx, int val, int n) {
    while (idx <= n) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

void print(int *ar, int n) {
    for (int i = 1; i <= n; ++i) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n; cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> ar[i];
        update(i, ar[i], n);
    }

    print(ar, n);
    print(tree, n);

    int query_idx;
    cin >> query_idx;
    cout << "Prefix sum up to index " << query_idx << ": " << read(query_idx) << "\n";

    return 0;
}
