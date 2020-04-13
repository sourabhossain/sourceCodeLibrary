/**
 * Name: Circular Doubly Linked List
 * Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

struct Node {
    Node *previous;
    int value;
    Node *next;
};
 
Node *head = NULL, *tail = NULL;

Node* get(int item) {
    Node *node = new Node();
    
    if(node == NULL) {
        puts("Error! Could not create a new node.");
        exit(1);
    }

    node->previous = node;
    node->value = item;
    node->next = node;
    
    return node;
} 

void pushFront(int value) {
    Node *node = get(value); 
    
    if(head == NULL) {
        head = node;
        tail = node;
    } else {
        node->next = head;
        node->previous = tail;
        head->previous = node;
        tail->next = node;
        head = node;
    }
} 

void popFront() {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    if(head == tail) {
        delete [] head;
        head = NULL;
        tail = head;
    } else {
        Node *node = head;
        
        head = head->next;
        head->previous = tail;
        tail->next = head;

        delete [] node;
    }
} 

void pushBack(int value) {
    Node *node = get(value);
    
    if(tail == NULL) {
        head = node;
        tail = node;
    } else {
        node->next = head;
        node->previous = tail;
        tail->next = node;
        tail = node;
        head->previous = tail;
    }
}  

void popBack() {
    if(tail == NULL) {
        puts("List is empty.");
        return;
    }
    
    
    if(head == tail) {
        delete [] tail;
        tail = NULL;
        head = tail;
    } else {
        Node *node = tail;

        tail = tail->previous;
        tail->next = head;
        head->previous = tail;

        delete [] node;
    }
}  

void insert(int key, int item) {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    Node *current = head, *previous = NULL;
    
    do {
        if(current->value == key) {
            if(previous == NULL) {
                pushFront(item);  
            } else {
                Node *newNode = get(item);  
                
                previous->next = newNode;
                newNode->next = current;
                newNode->previous = previous;
                current->previous = newNode;
            }
            
            return;
        }
        
        previous = current;
        current = current->next;
    }
    while(current != head);
    
    pushBack(item);  
}  

void erase(int item) {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    Node *current = head, *previous = NULL;
    
    do {
        if(current->value == item) {
            if(previous == NULL) {
                popFront();  
            } else if(current == tail) {
                popBack();  
            } else {
                current->previous->next = current->next;
                current->next->previous = current->previous;
                delete [] current;
            }
            
            return;
        }
        
        previous = current;
        current = current->next;
    }
    while(current != head);
}  

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}  

void sort() {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    Node *outerLoop = head;
    
    do {
        Node *innerLoop = outerLoop;
        
        do {
            if(outerLoop->value < innerLoop->value) {
                swap(&outerLoop->value, &innerLoop->value);  
            }
            
            innerLoop = innerLoop->next;
        }
        while(innerLoop != outerLoop);
        
        outerLoop = outerLoop->next;
    }
    while(outerLoop != head);
}  

bool search(int value) {
    if(head == NULL) {
        return false;
    }
    
    Node *searchNode = head;
    
    do {
        if(searchNode->value == value) {
            return true;
        }
        
        searchNode = searchNode->next;
    }
    while(searchNode != head);
    
    return false;
}  

int count(int item) {
    if(head == NULL) {
        return 0;
    }
    
    Node *countNode = head;
    int countValue = 0;
    
    do {
        if(countNode->value == item) {
            ++countValue;
        }
        
        countNode = countNode->next;
    }
    while(countNode != head);
    
    return countValue;
}  

int size() {
    if(head == NULL) {
        return 0;
    }
    
    Node *sizeNode = head;
    int nodeCount = 0;
    
    do {
        ++nodeCount;
        sizeNode = sizeNode->next;
    }
    while(sizeNode != head);
    
    return nodeCount;
}  

bool empty() {
    if(head == NULL || tail == NULL) {
        return true;
    }

    return false;
}  

void printFront() {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    Node *printNode = head;
    
    do {
        printf("%d ", printNode->value);
        printNode = printNode->next;
    }
    while(printNode != head);
    putchar('\n');
} 

void printBack() {
    if(tail == NULL) {
        puts("List is empty.");
        return;
    }
    
    Node *printNode = tail;
    
    do {
        printf("%d ", printNode->value);
        printNode = printNode->previous;
    }
    while(printNode != tail);
    putchar('\n');
}  

int main()
{
    pushBack(10);
    pushBack(20);
    pushBack(30);
    pushBack(40);
    pushBack(50);
    
    // erase(30);
    // erase(20);
    // erase(50);
    // erase(10);
    // erase(40);

    puts("-- Print Front --");
    printFront();

    puts("\n-- Print Back --");    
    printBack();

    delete [] head;
    delete [] tail;

    return 0;
}