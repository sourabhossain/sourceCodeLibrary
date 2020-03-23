/**
 *  Name: Insert Sort
 *  Author Name: Sourab Hossain
 */ 

#include <bits/stdc++.h>

void insertSort(vector<int>& data, int size) {
	for(int i = 1; i < size; i++) {
		int value = data[i];

		for(int j = i - 1; j >= 0; j--) {
			if(value < data[j]) {
				data[j + 1] = data[j];
			} else {
				break;
			}
		}

		data[j + 1] = value;
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
    
    insertSort(data, size);

    for(int i = 0; i < size; i++) {
    	printf("%d ", data[i]);
    } 
    putchar('\n');

	return 0;
}