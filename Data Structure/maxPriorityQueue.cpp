/**
 *  Name: Max Priority Queue
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

#define LEFT(n) (n << 1) 
#define RIGHT(n) ((n << 1) + 1)
#define PARENT(n) (n >> 1)

using namespace std;

void max_heapify(vector<int>& heap, int heap_size, int i) {
	int left = LEFT(i), right = RIGHT(i), largest;

	if(left <= heap_size && heap[left] > heap[i]) {
		largest = left;
	} else {
		largest = i;
	}

	if(right <= heap_size && heap[right] > heap[largest]) {
		largest = right;
	}

	if(largest != i) {
	    swap(heap[i], heap[largest]);
	    max_heapify(heap, heap_size, largest);
	}
} 

void max_heap(vector<int>& heap, int heap_size) {
	for(int i = heap_size >> 1; i >= 1; i--) {
		max_heapify(heap, heap_size, i);
	}
} 

void insert_item(vector<int>& heap, int& heap_size, int item) {
	heap.resize(heap_size + 2, item);
	heap_size++;

	int i = heap_size, p;

	while(i > 1 && heap[i] > heap[PARENT(i)]) {
		p = PARENT(i);
		swap(heap[p], heap[i]);
		i = p; 
	}
}

int extract_max(vector<int>& heap, int& heap_size) {
	int max_item = heap[1];

	heap[1] = heap[heap_size];
	max_heapify(heap, --heap_size, 1);

	return max_item;
}

int main()
{
	int heap_size; 

	scanf("%d", &heap_size);
	vector<int> heap(heap_size + 1);

	for(int i = 1; i <= heap_size; i++) {
		scanf("%d", &heap[i]);
	}

	max_heap(heap, heap_size);
	insert_item(heap, heap_size, 100);

	while(heap_size) {
		printf("%d ", extract_max(heap, heap_size));
	}
	putchar('\n');

	return 0;
}