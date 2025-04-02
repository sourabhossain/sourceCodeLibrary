/**
 *  Name: Segment Tree (Lazy Propagation)
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

#define LEFT(n) (n << 1)
#define RIGHT(n) ((n << 1) + 1)
#define MID(start, end) (start + ((end - start) >> 1))

using namespace std;

typedef long long i64;
const int mx = 1e5 + 5;

struct info {
    i64 prop, sum;
} tree[mx * 3];

void update(int node, int b, int e, int i, int j, i64 x) {
    if (i > e || j < b) {
        return;
    }

    if (b >= i && e <= j) {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }

    int Left = LEFT(node);
    int Right = RIGHT(node);
    int mid = MID(b, e);
    
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

i64 query(int node, int b, int e, int i, int j, i64 carry = 0) {
    if (i > e || j < b) {
        return 0;
    }

    if (b >= i && e <= j) {
        return tree[node].sum + carry * (e - b + 1);
    }
    
    int Left = LEFT(node);
    int Right = RIGHT(node);
    int mid = MID(b, e);
    
    return query(Left, b, mid, i, j, carry + tree[node].prop) + query(Right, mid + 1, e, i, j, carry + tree[node].prop);
}

void build(int node, int b, int e) {
    if (b == e) {
        tree[node].sum = 0;
        tree[node].prop = 0;
        return;
    }

    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    
    build(Left, b, mid);
    build(Right, mid + 1, e);
    
    tree[node].sum = tree[Left].sum + tree[Right].sum;
    tree[node].prop = 0;
}

int main() 
{
    int n, q, l, r, type;
    i64 val;
    cin >> n >> q;

    build(1, 1, n);

    while (q--) {
        cin >> type;

        if (type == 1) {
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        } else {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }

    return 0;
}
