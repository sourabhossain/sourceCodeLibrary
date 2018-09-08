/**
 *  Name: Insert Sort
 *  Author Name: Sourav Hossain
 */ 

#include <bits/stdc++.h>

void insertSort(int *data, int size) {
	for(int i = 1; i < size; i++) {
		int j, value = data[i];

		for(j = i - 1; j >= 0; j--) {
			if(value < data[j]) {
				data[j + 1] = data[j];
			} else {
				break;
			}
		}

		data[j + 1] = value;
	}
} // end insertSort function

int main()
{
	int size;

	scanf("%d", &size);

	int i, *data = new int(size);
   
    for(i = 0; i < size; i++) {
    	scanf("%d", &data[i]);
    }
    
    insertSort(data, size); // go to insert sort

    for(i = 0; i < size; i++) {
    	printf("%d ", data[i]);
    } 
    putchar('\n');

    delete [] data;
	return 0;
}