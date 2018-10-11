/**
 * Name: Circular Queue Array
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 101

int front = 0, rear = 0, data[SIZE];

void enqueue(int item) {
    int nextRear = (rear + 1) % SIZE;

    if(nextRear == front) {
        puts("Queue is full!");
        return;
    }

    data[rear] = item;
    rear = nextRear;
}  
 
void dequeue() {
    if(front == rear) {
        puts("Queue is empty!");
        return;
    }

    front = (front + 1) % SIZE;
}  
 
bool empty() {
    if(front == rear) {
        return true;
    }
    
    return false;
}  

int size() {
    if(front == rear) {
        return 0;
    }

    int sizeCount = 0;

    for(int i = front; i != rear; i = (i + 1) % SIZE) {
        sizeCount++;
    }

    return sizeCount;
}  

void print() {
    if(front == rear) {
        puts("Queue is empty!");
        return;
    }

    for(int i = front; i != rear; i = (i + 1) % SIZE) {
        printf("%d ", data[i]);
    }
    putchar('\n');
}  

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

	dequeue();

    print();

    printf("Size: %d\n", size());

    return 0;
}