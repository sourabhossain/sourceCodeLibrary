/**
 * Name: Circular Doubly Linked List
 * Author Name: Sourav Hossain
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
} // end get function

void pushFront(int value) {
    Node *node = get(value); // go to get function
    
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
} // end pushFront function

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
} // end popFront function

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
} // end pushBack function

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
} // end popBack function

void insert(int key, int item) {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    Node *currentNode = head, *previousNode = NULL;
    
    do {
        if(currentNode->value == key) {
            if(previousNode == NULL) {
                pushFront(item); // go to pushFront
            } else {
                Node *newNode = get(item); // go to get function
                
                previousNode->next = newNode;
                newNode->next = currentNode;
                newNode->previous = previousNode;
                currentNode->previous = newNode;
            }
            
            return;
        }
        
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    while(currentNode != head);
    
    pushBack(item); // go to pushBack function
} // end insert function

void erase(int item) {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    Node *currentNode = head, *previousNode = NULL;
    
    do {
        if(currentNode->value == item) {
            if(previousNode == NULL) {
                popFront(); // go to popFront function
            } else if(currentNode == tail) {
                popBack(); // go to popBack function
            } else {
                currentNode->previous->next = currentNode->next;
                currentNode->next->previous = currentNode->previous;
                delete [] currentNode;
            }
            
            return;
        }
        
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    while(currentNode != head);
} // end erase function

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
} // end swap function

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
                swap(&outerLoop->value, &innerLoop->value); // go to swap function
            }
            
            innerLoop = innerLoop->next;
        }
        while(innerLoop != outerLoop);
        
        outerLoop = outerLoop->next;
    }
    while(outerLoop != head);
} // end sort function

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
} // end search function

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
} // end count function

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
} // end size function

bool empty() {
    if(head == NULL || tail == NULL) {
        return true;
    }

    return false;
} // end empty function

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
} // end printFront function

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
} // end printBack function

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