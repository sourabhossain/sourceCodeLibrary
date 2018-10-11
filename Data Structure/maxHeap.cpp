/**
 *  Name: Max Heap
 *  Author Name: Sourav Hossain 
 */

#include <bits/stdc++.h>

#define LEFT(n) (n << 1)
#define RIGHT(n) ((n << 1) + 1)
#define PARENT(n) (n >> 1)

using namespace std;

bool is_max_heap(vector<int>& heap, int heap_size) {
	for(int i = heap_size, parent; i > 1; i--) {
		parent = PARENT(i);

		if(heap[parent] < heap[i]) {
			return false;
		}
	}

	return true;
}

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

void heap_sort(vector<int>& heap, int heap_size) {
	while(heap_size > 1) {
		swap(heap[1], heap[heap_size]);
		max_heapify(heap, --heap_size, 1);
	}
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
	heap_sort(heap, heap_size);

	for(int i = 1; i <= heap_size; i++) {
		printf("%d ", heap[i]);
	}
	putchar('\n');

	return 0;
}