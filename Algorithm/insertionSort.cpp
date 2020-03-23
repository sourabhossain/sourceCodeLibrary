/**
 * Name: Insertion Sort
 * Autor Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int>& data, int length) {
    for(int i = 1; i < length; i++) {
        for(int j = i; j > 0 && data[j - 1] > data[j]; j--) {                 
            swap(data[j - 1], data[j]);     
        }
    }
}

int main()
{
    int length; 
   
    scanf("%d", &length);
    vector<int> data(length);
    
    for(int i = 0; i < length; i++) {
        scanf("%d", &data[i]);
    }
    
    insertionSort(data, length);

    for(int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');
    
    return 0;
}