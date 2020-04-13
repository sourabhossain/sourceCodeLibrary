/**
 *  Name: Min Heap
 *  Author Name: Sourab Hossain 
 */

#include <bits/stdc++.h>

#define LEFT(n) (n << 1)
#define RIGHT(n) ((n << 1) + 1)
#define PARENT(n) (n >> 1) 

using namespace std;

bool is_min_heap(vector<int>& heap, int heap_size) {
	for(int i = heap_size, parent; i > 1; i--) {
		parent = PARENT(i);

		if(heap[parent] > heap[i]) {
			return false;
		}
	}

	return true;
}

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

void heap_sort(vector<int>& heap, int heap_size) {
	while(heap_size > 1) {
		swap(heap[1], heap[heap_size]);
		min_heapify(heap, --heap_size, 1);
	}
}

int main()
{
	int n;

	scanf("%d", &n);
	vector<int> heap(n + 1);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &heap[i]);
	}
    
    min_heap(heap, n);
    heap_sort(heap, n);

	for(int i = 1; i <= n; i++) {
		printf("%d ", heap[i]);
	}
	putchar('\n');

	return 0;
}