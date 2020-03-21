/**
 * Name: Radix Sort
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int getMaximum(int *data, int n) {
    int maximum = data[0];

    for(int i = 1; i < n; i++) {
        maximum = max(maximum, data[i]);
    }

    return maximum;
}

void countSort(int *data, int n, int exp) {
    int output[n], count[10] = {0};

    for(int i = 0; i < n; i++) {
        count[(data[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        output[--count[(data[i] / exp) % 10]] = data[i];
    }

    for(int i = 0; i < n; i++) {
        data[i] = output[i];
    }
}

void radixSort(int *data, int n) {
    int maximum = getMaximum(data, n);

    for(int exp = 1; maximum / exp > 0; exp *= 10) {
        countSort(data, n, exp);
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    int data[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    radixSort(data, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');

    return 0;
}
