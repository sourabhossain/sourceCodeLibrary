/**
 *  Name: Stack Linked List
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *head = NULL;

Node* get(int item) {
    Node *node = new Node();

    if(node == NULL) {
        puts("Error! Could not create a new node");
        exit(1);
    }

    node->value = item;
    node->next = NULL;

    return node;
}  

void push(int item) {
    Node *node = get(item);  

    node->next = head;
    head = node;
}  

void pop() {
    if(head == NULL) {
        puts("Stack is empty.");
        return;
    }

    Node *node = head->next;
    delete [] head;
    head = node;
}  

int size() {
    if(head == NULL) {
        return 0;
    }

    int sizeCount = 0;

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        sizeCount++;
    }

    return sizeCount;
}  

int top() {
    if(head == NULL) {
        return -1;
    }

    return head->value;
} 

int back() {
    if(head == NULL) {
        return -1;
    }

    Node *iterator = head;

    while(iterator->next != NULL) {
        iterator = iterator->next;
    }

    return iterator->value;
}  

bool empty() {
    if(head == NULL) {
        return true;
    }

    return false;
}  

void print() {
    if(head == NULL) {
        puts("Stack is empty.");
        return;
    }

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        printf("%d ", iterator->value);
    }
    putchar('\n');
}  

void clear() {
    if(head == NULL) {
        return;
    }

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        delete [] iterator;
    }

    head = NULL;
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

    printf("\nSize: %d\n", size());
    printf("empty: %d\n", empty());

    clear();
    return 0;
}
