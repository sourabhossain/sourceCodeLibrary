/**
 * Name: Queue Array
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

int top = 0, *data;

void resize() {
    int *newArray = new int[top + 1];

    for(int i = 0; i < top; i++) {
        newArray[i] = data[i];
    }

    delete [] data;
    data = newArray;
} // end resize function

void free() {
    int *newArray = new int[top - 1];

    for(int i = 1; i < top; i++) {
        newArray[i - 1] = data[i];
    }

    delete [] data;
    data = newArray;
} // end free function

void push(int value) {
    resize(); // go to resize function
    data[top] = value;
    top += 1;
} // end push function

void pop() {
    free(); // go to free function
    top -= 1;
} // end pop function

int size() {
    if(top == 0) {
        return 0;
    }

    return top;
} // end size function

bool empty() {
    if(top == 0) {
        return true;
    }

    return false;
} // end empty function

void print() {
    if(top == 0) {
        puts("Queue is empty!");
        return;
    }

    for(int i = 0; i < top; i++) {
        printf("%d ", data[i]);
    }
    putchar('\n');
} // end print function

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    pop();
    pop();

    print();

    return 0;
}