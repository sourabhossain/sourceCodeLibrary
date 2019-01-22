/**
 * Name: NOD Number
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void nod(int n) {
    int root = sqrt(n);
    set<int> s;

    s.insert(1);
    s.insert(n);

    for(int i = 2; i <= root; i++) {
        if(n % i == 0) {
            s.insert(i);
            s.insert(n / i);
        }
    }

    for(set<int>::iterator it = s.begin(); it != s.end();) {
        cout << *it;

        if(++it != s.end()) {
            putchar(' ');
        }
    }
    putchar('\n');
}

int main()
{
    int n;

    scanf("%d", &n);
    cout << n << " = ";
    nod(n);

    return 0;
}