/**
 * Name: Recursive Bubble Sort
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int *data, int n) {
    if(n == 1) {
        return;
    }

    for(int i = 1; i < n; i++) {
        if(data[i - 1] > data[i]) {
            swap(data[i - 1], data[i]);
        }
    }

    bubbleSort(data, n - 1);
}

int main()
{
    int n;

    scanf("%d", &n);
    int data[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    bubbleSort(data, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');

    return 0;
}
