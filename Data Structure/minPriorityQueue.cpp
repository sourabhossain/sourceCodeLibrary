/**
 *  Name: Min Priority Queue
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

#define LEFT(n) (n << 1) 
#define RIGHT(n) ((n << 1) + 1)
#define PARENT(n) (n >> 1)

using namespace std;

void min_heapify(vector<int>& heap, int heap_size, int i) {
	int left = LEFT(i), right = RIGHT(i), smallest;

	if(left <= heap_size && heap[left] < heap[i]) {
		smallest = left;
	} else {
		smallest = i;
	}

	if(right <= heap_size && heap[right] < heap[smallest]) {
		smallest = right;
	}

	if(smallest != i) {
		swap(heap[i], heap[smallest]);
		min_heapify(heap, heap_size, smallest);
	}
}

void min_heap(vector<int>& heap, int heap_size) {
	for(int i = heap_size >> 1; i >= 1; i--) {
		min_heapify(heap, heap_size, i);
	}
}

void insert_item(vector<int>& heap, int& heap_size, int item) {
	heap.resize(heap_size + 2, item);
	heap_size++;

	int i = heap_size, p;

	while(i > 1 && heap[i] < heap[PARENT(i)]) {
		p = PARENT(i);
		swap(heap[p], heap[i]);
		i = p;
	}
}

int extract_min(vector<int>& heap, int& heap_size) {
	int min_item = heap[1];

	heap[1] = heap[heap_size];
	min_heapify(heap, --heap_size, 1);

	return min_item;
}

int main()
{
	int heap_size;

	scanf("%d", &heap_size);
	vector<int> heap(heap_size + 1);

	for(int i = 1; i <= heap_size; i++) {
		scanf("%d", &heap[i]);
	}

	min_heap(heap, heap_size);
	insert_item(heap, heap_size, 10);
    
    while(heap_size) {
    	printf("%d ", extract_min(heap, heap_size));
    }
    putchar('\n');

	return 0;
}