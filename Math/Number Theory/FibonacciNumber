/**
  *  Name: Fibonacci Number
  *  Author Name: Sourab Hossain
  */

#include <bits/stdc++.h>

using namespace std;

int fibonacciNumber(int n) {
    int a = 0, b = 1;

    while(n--) {
        b += a;
        a = b - a;
    }

    return b;
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", fibonacciNumber(n));

    return 0;
}
