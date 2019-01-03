/**
 * Name: Circular Singly Linked List
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

struct Node {
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

    node->value = item;
    node->next = node;
    
    return node;
}  

void pushFront(int item) {
    Node *node = get(item);  
    
    if(head == NULL) {
        head = node;
        tail = node;
    } else {
        node->next = head;
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
        Node *currentNode = head->next;
        delete [] head;
        head = currentNode;
        tail->next = head;
    }
}   

void pushBack(int item) {
    Node *node = get(item);  
    
    if(tail == NULL) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        node->next = head;
        tail = node;
    }
}  

void popBack() {
    if(tail == NULL) {
        puts("List is empty.");
        return;
    }
    
    if(head == tail) {
        delete [] head;
        head = NULL;
        tail = head;
    } else {
        Node *currentNode = head, *perviousNode = head;
        
        while(currentNode->next != head) {
            perviousNode = currentNode;
            currentNode = currentNode->next;
        }
        
        perviousNode->next = head;
        tail = perviousNode;
        delete [] currentNode;
    }
}  

void insert(int key, int item) {
    if(head == NULL || tail == NULL) {
        puts("List is empty.");
        return;
    }
    
    Node *currentNode = head, *perviousNode = NULL;
    
    do {
        if(currentNode->value == key) {
            if(perviousNode == NULL) {
                pushFront(item);  
            } else {
                Node *newNode = get(item);  
                newNode->next = currentNode;
                perviousNode->next = newNode;
            }
            return;
        }
        
        perviousNode = currentNode;
        currentNode = currentNode->next;
    } while(currentNode != head);
    
    pushBack(item);  
}  

void erase(int item) {
    if(head == NULL || tail == NULL) {
        puts("List is empty.");
        return;
    }
    
    Node *currentNode = head, *perviousNode = NULL;
    
    do {
        if(currentNode->value == item) {
            if(perviousNode == NULL) {
                popFront();  
            } else if(currentNode == tail) {
                popBack();
            } else {
                perviousNode->next = currentNode->next;
                delete [] currentNode;
            }
            return;
        }
        
        perviousNode = currentNode;
        currentNode = currentNode->next;
    } while(currentNode != head);
}  

bool empty() {
    if(head == NULL || tail == NULL) {
        return true;
    } 

    return false;
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
        } while(innerLoop != outerLoop);
        
        outerLoop = outerLoop->next;
    } while(outerLoop != head);
}  

bool search(int value) {
    if(head == NULL || tail == NULL) {
        return 0;
    }
    
    Node *searchNode = head;
    
    do {
        if(searchNode->value == value) {
            return true;
        }
        
        searchNode = searchNode->next;
    } while(searchNode != head);
    
    return false;
}  

int size() {
    if(head == NULL || tail == NULL) {
        return 0;
    }
    
    Node *sizeNode = head;
    int nodeCount = 0; 
    
    do {
        ++nodeCount;
        sizeNode = sizeNode->next;
    } while(sizeNode != head);
    
    return nodeCount;
}  

int count(int value) {
    if(head == NULL || tail == NULL) {
        return 0;
    }
    
    Node *countNode = head;
    int countValue = 0;
    
    do {
        if(countNode->value == value) {
            countValue++;
        }
        
        countNode = countNode->next;
    } while(countNode != head);
    
    return countValue;
}  

void print() {
    if(head == NULL || tail == NULL) {
        puts("List is empty.");
        return;
    }
    
    Node *printNode = head;
    
    do {
        printf("%d ", printNode->value);
        printNode = printNode->next;
    } while(printNode != head);
    putchar('\n');
} 

int main()
{
    pushBack(20);
    pushBack(50);
    pushBack(40);
    pushBack(30);
    pushBack(10);  
    
    // sort();
    
    // erase(30);
    // erase(50);
    // erase(40);

    print();

    delete [] head;
    delete [] tail;
    return 0;
}