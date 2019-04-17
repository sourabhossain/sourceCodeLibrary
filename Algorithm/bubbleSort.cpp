/**
 * Name: Bubble Sort
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& data, int length) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = i + 1; j < length; j++) {
            if(data[i] > data[j]) {
               swap(data[i], data[j]);
            }
        }
    }
}

void bubbleSort(vector<int>& data, int length) {
    for(int i = length; i > 0; i--) {
        for(int j = 0; j < i - 1; j++) {
            if(data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
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

    bubbleSort(data, length);

    for(int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');
    
	return 0;
}