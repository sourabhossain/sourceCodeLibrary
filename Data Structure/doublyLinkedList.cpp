/**
 * Name: Doubly Linked List
 * Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

struct Node {
    Node *pervious;
    int value;
    Node *next;
};

Node *head = NULL, *tail = NULL;

Node* get(int item) {
    Node *node = new Node();
    
    if(node == NULL) {
        puts("Error! Could not create a new node");
        exit(1);
    }
    
    node->pervious = NULL;
    node->value = item;
    node->next = NULL;

    return node;
} // end get function

void pushFront(int item) {
    Node *node = get(item); // go to get function

    if(head == NULL) {
        head = node;
        tail = head;
    } else {
        node->next = head;
        head->pervious = node;
        head = node;
    }
} // end pushFront function

void popFront() {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }

    Node *node = head;

    if(node->next == NULL) {
        node = node->next;
        tail = node;
    } else {
        node = node->next;
        node->pervious = NULL;
    }

    delete [] head;
    head = node;
} // end popFront function

void pushBack(int item) {
    Node *node = get(item); // go to get function

    if(head == NULL) {
        head = node;
        tail = head;
    }
    else {
        tail->next = node;
        node->pervious = tail;
        tail = node;
    }
} // end pushBack function

void popBack() {
    if(tail == NULL) {
        puts("List is empty.");
        return;
    }

    Node *node = tail;

    if(node->pervious == NULL) {
        node = node->pervious;
        head = node;
    } else {
        node = node->pervious;
        node->next = NULL;
    }

    delete [] tail;
    tail = node;
} // end popBack function

int count(int item) {
    if(head == NULL || tail == NULL) {
        return 0;
    }

    int countValue = 0;

    for(Node *countNode = head; countNode != NULL; countNode = countNode->next) {
        if(countNode->value == item) {
            ++countValue;
        }
    }

    return countValue;
} // end count function

int size() {
    if(head == NULL) {
        return 0;
    }

    int nodeCount = 0;

    for(Node *sizeNode = head; sizeNode != NULL; sizeNode = sizeNode->next) {
        ++nodeCount;
    }

    return nodeCount;
} // end size function

bool empty() {
    if(head == NULL || tail == NULL) {
        return true;
    }
    
    return false;
} // end empty function

bool search(int item) {
    if(head == NULL) {
        return false;
    }

    for(Node *searchNode = head; searchNode != NULL; searchNode = searchNode->next) {
        if(searchNode->value = item) {
            return true;
        }
    }

    return false;
} // end search function

void insert(int key, int item) {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    for(Node *currentNode = head, *insertNode = NULL; currentNode != NULL; insertNode = currentNode, currentNode = currentNode->next) {
        if(currentNode->value == key) {
            if(insertNode == NULL) {
                pushFront(item); // go to pushFront function
            } else {
                Node *pushNode = get(item); // go to get function
                
                pushNode->next = currentNode;
                pushNode->pervious = insertNode;
                insertNode->next = pushNode;
                currentNode->pervious = pushNode;
            }

            return;
        }
    }
    
    pushBack(item); // go to pushBack function
} // end insert function

void erase(int item) {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    for(Node *currentNode = head, *popNode = NULL; currentNode != NULL; popNode = currentNode, currentNode = currentNode->next) {
        if(currentNode->value == item) {
            if(popNode == NULL) {
                popFront(); // go to popFront function
            } else if(currentNode == tail) {
                popBack(); // go to popBack function
            } else {
                currentNode->pervious->next = currentNode->next;
                currentNode->next->pervious = currentNode->pervious;
                delete [] currentNode;
            }
            
            return;
        }
    }
} // end erase function

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b; 
} // end swap function

void sort() {
    for(Node *outerLoop = head; outerLoop != NULL; outerLoop = outerLoop->next) {
        for(Node *innerLoop = outerLoop->next; innerLoop != NULL; innerLoop = innerLoop->next) {
            if(outerLoop->value > innerLoop->value) {
                swap(&outerLoop->value, &innerLoop->value);
            }
        }
    }
} // end sort function

void printFront() {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }

    for(Node *printNode = head; printNode != NULL; printNode = printNode->next) {
        printf("%d ", printNode->value);
    }
    putchar('\n');
} // end printFront function

void printBack() {
    if(tail == NULL) {
        puts("List is empty.");
        return;
    }

    for(Node *printNode = tail; printNode != NULL; printNode = printNode->pervious) {
        printf("%d ", printNode->value);
    }
    putchar('\n');
} // end printBack function

int main()
{
    pushBack(10);
    pushBack(20);
    pushBack(30);
    pushBack(40);
    pushBack(50);
    
    insert(10, 5);
    insert(30, 25);
    insert(50, 45);
    insert(100, 55);
    
    erase(5);
    erase(55);
    erase(25);
    erase(30);

    puts("-- Print Front --");
    printFront();

    puts("\n-- Print Back --");
    printBack();

    delete [] head;
    delete [] tail;
    return 0;
}