/**
 * Name: Insertion Sort
 * Autor Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void insertionSort(int *data, int length) {
    for(int i = 1; i < length; i++) {
        for(int j = i; data[j - 1] > data[j] && j > 0; j--) {
            data[j - 1] ^= data[j];     
            data[j] ^= data[j - 1];                 
            data[j - 1] ^= data[j];     
        }
    }
} // end insertionSort function

int main()
{
    int length; 
   
    scanf("%d", &length);
    
    int *data = new int(length);
    
    for(int i = 0; i < length; i++) {
        scanf("%d", &data[i]);
    }
    
    insertionSort(data, length); // go to insertionSort function

    for(int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');
    
    delete [] data;
    return 0;
}