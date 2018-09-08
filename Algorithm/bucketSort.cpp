/**
 * Name: Bucket Sort
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 102

int bucket[SIZE];

void bucketSort(int *data, int size) {
	for(int i = 0; i < size; i++) {
		bucket[data[i]]++;
	}

	for(int i = 0, k = 0; i < SIZE; i++) {
		for(int j = 0; j < bucket[i]; j++) {
			data[k++] = i;
		}
	}
} // end bucketSort function

int main()
{
	int size;

	scanf("%d", &size);

	int *data = new int(size);
   
    for(int i = 0; i < size; i++) {
    	scanf("%d", &data[i]);
    }
    
    bucketSort(data, size); // go to bucketSort function

    for(int i = 0; i < size; i++) {
    	printf("%d ", data[i]);
    }
    putchar('\n');

    delete [] data;
	return 0;
}