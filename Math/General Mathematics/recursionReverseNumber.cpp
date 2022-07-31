/**
 * Name: Recursion Reverse Number
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

unsigned long numberOfMultiples(unsigned long n) {
    if(n < 10) {
        return 1;
    }

    return 10 * numberOfMultiples(n / 10);
}

unsigned long reverse(unsigned long n) {
    if(n < 10) {
        return n % 10;
    }

    return  n % 10 * numberOfMultiples(n) + reverse(n / 10) ;
}

int main()
{
    unsigned long n;

    cin >> n;
    cout << reverse(n) << endl;

    return 0;
}
