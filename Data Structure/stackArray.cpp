/**
 * Name: Stack Array
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

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
    int *newArray = new int[top];

    for(int i = 0; i < top; i++) {
        newArray[i] = data[i];
    }

    delete [] data;
    data = newArray;
} // end free function

void push(int value) {
    resize(); // go to resize function
    data[top++] = value;
} // end push function

void pop() {
    if(top == 0) {
        puts("Stack is empty");
    } else {
        free(); // go to free function
        --top;
    }
} // end pop function

int size() {
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
        puts("Stack is empty");
    } else {

        for(int i = top - 1; i >= 0; i--) {
            printf("%d ", data[i]);
        }
        putchar('\n');
    }
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
    
    delete [] data;
    return 0;
}