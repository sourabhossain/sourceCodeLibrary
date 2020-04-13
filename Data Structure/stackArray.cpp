/**
 * Name: Stack Array
 * Author Name: Sourab Hossain
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
}  

void free() {
    int *newArray = new int[top];

    for(int i = 0; i < top; i++) {
        newArray[i] = data[i];
    }

    delete [] data;
    data = newArray;
}  

void push(int value) {
    resize();  
    data[top++] = value;
}  

void pop() {
    if(top == 0) {
        puts("Stack is empty");
    } else {
        free();  
        --top;
    }
}  

int size() {
    return top;
}  

bool empty() {
    if(top == 0) {
        return true;
    }

    return false;
} 

void print() {
    if(top == 0) {
        puts("Stack is empty");
    } else {

        for(int i = top - 1; i >= 0; i--) {
            printf("%d ", data[i]);
        }
        putchar('\n');
    }
}  

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