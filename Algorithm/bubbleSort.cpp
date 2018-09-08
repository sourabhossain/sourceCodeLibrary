/**
 * Name: Bubble Sort
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int *data, int length) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = i + 1; j < length; j++) {
            if(data[i] > data[j]) {
               data[i] ^= data[j];
               data[j] ^= data[i];
               data[i] ^= data[j];
            }
        }
    }
} // end bubbleSort function

int main()
{
    int length;

    scanf("%d", &length);
    int *data = new int(length);
    
    for(int i = 0; i < length; i++) {
        scanf("%d", &data[i]);
    }

    bubbleSort(data, length); // go to bubbleSort function

    for(int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');
    
    delete [] data;
	return 0;
}