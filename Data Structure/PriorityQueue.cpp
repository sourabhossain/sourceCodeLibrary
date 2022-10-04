#include <bits/stdc++.h>

using namespace std;

class PriorityQueue {
    private:
        vector<int> pq;

    public:
        PriorityQueue() {}

        bool isEmpty() {
            return pq.size() == 0;
        }

        int getSize() {
            return pq.size();
        }

        void insert(int element) {
             pq.push_back(element);
             int childIndex = getSize() - 1;

             while(childIndex > 0) {
                 int parentIndex = (childIndex - 1) / 2;

                 if(pq[parentIndex] > pq[childIndex]) {
                     swap(pq[parentIndex], pq[childIndex]);
                 } else {
                     break;
                 }

                 childIndex = parentIndex;
             }
        }

        int removeMinimum() {
             if(getSize() == 0) {
                 return -1;
             }

             int minimumValue = pq[0];
             int size = getSize() - 1;
             swap(pq[0], pq[size]);
             pq.pop_back();

             int parentIndex = 0;
             int leftChildIndex = 2 * parentIndex + 1;
             int rightChildIndex = 2 * parentIndex + 2;
             int minIndex = 0;

             while(leftChildIndex < size) {
                 if(pq[leftChildIndex] < pq[parentIndex]) {
                     minIndex = leftChildIndex;
                 }

                 if(rightChildIndex < size && pq[rightChildIndex] < pq[minIndex]) {
                     minIndex = rightChildIndex;
                 }

                 if(minIndex == parentIndex) {
                     break;
                 }

                 swap(pq[minIndex], pq[parentIndex]);
                 parentIndex = minIndex;
                 leftChildIndex = 2 * parentIndex + 1;
                 rightChildIndex = 2 * parentIndex + 2;
             }

             return minimumValue;
        }
};

int main()
{
    PriorityQueue pq;

    for(int i = 5; i >= 1; i--) {
        pq.insert(i);
    }

    while(!pq.isEmpty()) {
        cout << pq.removeMinimum() << endl;
    }

    return 0;
}
