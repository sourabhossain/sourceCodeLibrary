/**
 * Name: Recursive Insertion Sort
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void insertionSort(int *data, int n) {
    if(n < 0) {
        return;
    }

    insertionSort(data, n - 1);

    int last = data[n - 1], j = n - 2;

    while(j >= 0 && data[j] > last) {
        data[j + 1] = data[j];
        j--;
    }

    data[j + 1] = last;
}

int main()
{
    int n;

    scanf("%d", &n);
    int data[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    insertionSort(data, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');

    return 0;
}
