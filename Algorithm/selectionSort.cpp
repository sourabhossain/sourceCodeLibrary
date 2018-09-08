/**
 * Name: Selection Sort
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void selectionSort(int *data, int length) {
    for(int i = 0; i < length - 1; i++) {
        int minIndex = i;

		for(int j = i + 1; j < length; j++) {
            if(data[j] < data[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex ^ i) {
           data[i] ^= data[minIndex];
           data[minIndex] ^= data[i];
           data[i] ^= data[minIndex];
        }
	}
} // end selectionSort function

int main()
{
    int size;

    scanf("%d", &size);

    int *data = new int(size);

    for(int i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }

    selectionSort(data, size); // go to selectionSort function
    
    for(int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');

    delete [] data;
	return 0;
}
