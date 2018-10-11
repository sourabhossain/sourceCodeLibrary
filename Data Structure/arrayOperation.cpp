/**
 *  Name: Array Operation
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>
#define SIZE 1002

int top = 0, data[SIZE];

void pushFront(int item) {
    if(top == SIZE) {
        puts("Array is overflow");
        return;
    }

    for(int i = top++; i > 0; i--) {
        data[i] = data[i - 1];
    }

    data[0] = item;
} 

void popFront() {
    if(top == 0) {
        puts("Array is empty");
        return;
    }

    for(int i = 1; i < top; ++i) {
        data[i - 1] = data[i];
    }

    --top;
} 

void pushBack(int item) {
    if(top == SIZE) {
        puts("Array is overflow");
        return;
    }

    data[top++] = item;
} 

void popBack() {
    if(top == 0) {
        puts("Array is empty!");
        return;
    }

    --top;
}  

void insert(int item, int position) {
    if(position < 1 || position - 1 > top) {
        printf("Error! %d number position does not access!\n", position);
        return;
    }

    if(position + 1 == SIZE) {
        puts("Array is Overflow");
        return;
    }

    for(int i = ++top; i >= position; i--) {
        data[i] = data[i - 1];
    }

    data[position - 1] = item;
}  

void erase(int item) {
    if(top == 0) {
        puts("Array is empty");
        return;
    }

    for(int i = 0; i < top; i++) {
        if(data[i] == item) {
            for(int j = i + 1; j < top; j++) {
                data[j - 1] = data[j];
            }

            --top;
            return;
        }
    }
}  

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
} 

void sort() {
    for(int i = 1; i < top; i++) {
        for(int j = i; data[j - 1] > data[j] && j > 0; j--) {
            swap(&data[j-1], &data[j]);  
        }
    }
}  

bool empty() {
    if(top == 0) {
        return true;
    }

    return false;
}  

int size() {
    return top;
}  

void print() {
    if(top == 0) {
        puts("Array is empty!");
        return;
    }

    for(int i = 0; i <  top; ++i) {
        printf("%d ", data[i]);
    }
    putchar('\n');
} 

int main()
{
    pushBack(60);
    pushBack(50);
    pushBack(30);
    pushBack(20);
    pushBack(40);
    pushBack(10);
    
    sort();

    print();

    return 0;
}
