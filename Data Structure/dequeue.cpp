/**
 *  Name: Double Ended Queue
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>
#define SIZE 101

using namespace std;

int data[SIZE], front = -1, rear = 0;

bool isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

bool isEmpty() {
    return front == -1;
}

void pushFront(int item) {
    if(isFull()) {
    	puts("Overflow!");
    	return;
    }

    if(front == -1) {
    	front = rear = 0;
    } else if(front == 0) {
    	front = SIZE - 1;
    } else {
    	front--;
    }

    data[front] = item;
}

void pushBack(int item) {
    if(isFull()) {
    	puts("Overflow!");
    	return;
    }

    if(front == -1) {
    	front = rear = 0;
    } else if(rear == SIZE - 1) {
    	rear = 0;
    } else {
    	rear++;
    }

    data[rear] = item;
}

void popFront() {
	if(isEmpty()) {
		puts("Underflow!");
		return;
	}

	if(front == rear) {
		front = rear = -1;
	} else {
		if(front == SIZE - 1) {
			front = 0;
		} else {
			front++;
		}
	}
}

void popBack() {
	if(isEmpty()) {
		puts("Underflow!");
		return;
	}

	if(front == rear) {
		front = rear = -1;
	} else if(rear == 0) {
		rear = SIZE - 1;
	} else {
		rear--;
	}
}

int getFront() {
	if(isEmpty()) {
		puts("Underflow!");
		return -1;
	}

	return data[front];
}

int getBack() {
	if(isEmpty() || rear < 0) {
		puts("Underflow!");
		return -1;
	}

	return data[rear];
}

int main()
{
    pushFront(10);
    pushFront(20);
    pushBack(30);
    pushFront(40);

    // 40 20 10 30
    while(!isEmpty()) {
        cout << getFront() << " ";
        popFront();
    }
    cout << endl;

    pushFront(10);
    pushFront(20);
    pushBack(30);
    pushFront(40);

    // 30 10 20 40
    while(!isEmpty()) {
        cout << getBack() << " ";
        popBack();
    }
    cout << endl;

	return 0;
}