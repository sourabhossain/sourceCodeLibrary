#include <bits/stdc++.h>

using namespace std;

int main()
{
    int coins[] = {100, 50, 20, 10, 5, 2, 1};
    int totalChange;
    int result = 0;

    cin >> totalChange;

    for(int i = 0; i < 7; i++) {
        while(totalChange >= coins[i]) {
            result++;
            totalChange -= coins[i];
        }
    }

    cout << result << endl;

    return 0;
}
