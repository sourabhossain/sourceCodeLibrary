/**
 * Name: N Number GCD
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

int gcd(int first, int second)
{
    int temp;

    while (second)
    {
        temp = second;
        second = first % second;
        first = temp;
    }

    return first;
}

int n_gcd(int *data, int n)
{
    int i, GCD = data[0];

    for (i = 1; i < n; i++)
    {
        GCD = gcd(GCD, data[i]);

        if (GCD == 1)
        {
            return 1;
        }
    }

    return GCD;
}

int main()
{
    int n;

    scanf("%d", &n);
    int data[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    printf("%d\n", n_gcd(data, n));

    return 0;
}