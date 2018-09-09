/**
 *  Name: Counting Sort
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 101

int count[SIZE];

void countingSort(vector<int>& data, int size) {
    for(int i = 0; i < size; i++) {
        count[data[i]]++;
    }

    for(int i = 0, k = 0; i < SIZE; i++) {
        for(int j = 0; j < count[i]; j++) {
            data[k++] = i;
        }
    }
}

int main()
{
    int size;

    scanf("%d", &size);
    vector<int> data(size);

    for(int i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }

    countingSort(data, size);

    for(int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');

    return 0;
}
