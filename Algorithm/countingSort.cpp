/**
 *  Name: Counting Sort
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 101

int count[SIZE];

void countingSort(int *data, int size) {
    for(int i = 0; i < size; i++) {
        count[data[i]]++;
    }

    for(int i = 0, k = 0; i < SIZE; i++) {
        for(int j = 0; j < count[i]; j++) {
            data[k++] = i;
        }
    }
} // end countingSort

int main()
{
    int size;

    scanf("%d", &size);

    int *data = new int(size);

    for(int i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }

    countingSort(data, size); // go to countingSort function

    for(int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');

    delete [] data;
    return 0;
}
