/**
  *  Name: Factors Count
  *  Author Name: Sourab Hossain
  */
#include <bits/stdc++.h>

using namespace std;

int factorsCount(int n) {
    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;

            if (i != n / i) {
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);

    int n;

    cin >> n;
    cout << factorsCount(n) << endl;

    return 0;
}
