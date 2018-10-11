/**
 * Name: Sort Singly Linked List
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

struct Node {
    int value;
    Node *next;
};

Node *head = NULL;

Node* get(int item) {
    Node *node = new Node();
    
    if(node == NULL) {
        puts("Error! Could not create a new node.");
        exit(1);
    }

    node->value = item;
    node->next = NULL;

    return node;
}  

void insert(int item) {
    Node *node = get(item);  
    
    if(head == NULL || node->value < head->value) {
        node->next = head;
        head = node;
    } else {
        Node *previous = head, *current = head->next;

        while(current != NULL && node->value > current->value) {
            previous = current;
            current = current->next;
        }

        previous->next = node;
        node->next = current;
    }
}  

void erase(int item) {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }

    for(Node *current = head, *previous = NULL; current != NULL; previous = current, current = current->next) {
        if(current->value == item) {
            if(previous == NULL) {
                current = head->next;
                delete [] head;
                head = current;
            } else {
                previous->next = current->next;
                delete [] current;
                current = previous;
            }

            return;
        }
    }
}  

void popFront() {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }

    Node *node = head->next;
    delete [] head;
    head = node;
}  

void popBack() {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    if(head->next == NULL) {
        delete [] head;
        head = NULL;
    } else {
        Node *current = head, *previous = NULL;

        while(current->next != NULL) {
            previous = current;
            current = current->next;
        }

        previous->next = NULL;
        delete [] current;
    }
}  

void reverse() {
    if(head == NULL) {
        return;
    }

    Node *iterator = head, *reverseNode = NULL, *temp;
    
    while(iterator != NULL) {
        temp = reverseNode;
        reverseNode = iterator;
        iterator = iterator->next;
        reverseNode->next = temp;
    }

    head = reverseNode;
}  

bool search(int item) {
    if(head == NULL) {
        return false;
    }

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        if(iterator->value == item) {
            return true;
        }
    }

    return false;
}  

int size() {
    if(head == NULL) {
        return 0;
    }

    int nodeCount = 0;

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        nodeCount += 1;
    }

    return nodeCount;
}  

bool empty() {
    if(head == NULL) {
        return true;
    }

    return false;
}  

void print() {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        printf("%d ", iterator->value);
    }
    putchar('\n');
}  

void clear() {
    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        delete [] iterator;
    }
}  

int main()
{
    insert(50);
    insert(10);
    insert(20);
    insert(40);
    insert(30);
    insert(10);
    insert(30);

    // popFront();
    // popBack();

    // erase(50);
    // erase(30);
    // erase(40);
    // erase(10);
    // erase(20);

    reverse();

    print();

    clear();
    return 0;
}