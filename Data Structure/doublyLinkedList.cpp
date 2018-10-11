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
} 

void pushFront(int item) {
    Node *node = get(item);  

    if(head == NULL) {
        head = node;
        tail = head;
    } else {
        node->next = head;
        head->pervious = node;
        head = node;
    }
}  

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
}  

void pushBack(int item) {
    Node *node = get(item);  

    if(head == NULL) {
        head = node;
        tail = head;
    } else {
        tail->next = node;
        node->pervious = tail;
        tail = node;
    }
}  

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
} 

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
}  

int size() {
    if(head == NULL) {
        return 0;
    }

    int nodeCount = 0;

    for(Node *sizeNode = head; sizeNode != NULL; sizeNode = sizeNode->next) {
        ++nodeCount;
    }

    return nodeCount;
}  

bool empty() {
    if(head == NULL || tail == NULL) {
        return true;
    }
    
    return false;
}  

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
}  

void insert(int key, int item) {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    for(Node *current = head, *insertNode = NULL; current != NULL; insertNode = current, current = current->next) {
        if(current->value == key) {
            if(insertNode == NULL) {
                pushFront(item);  
            } else {
                Node *pushNode = get(item);  
                
                pushNode->next = current;
                pushNode->pervious = insertNode;
                insertNode->next = pushNode;
                current->pervious = pushNode;
            }

            return;
        }
    }
    
    pushBack(item);  
}  

void erase(int item) {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }
    
    for(Node *current = head, *popNode = NULL; current != NULL; popNode = current, current = current->next) {
        if(current->value == item) {
            if(popNode == NULL) {
                popFront();  
            } else if(current == tail) {
                popBack();  
            } else {
                current->pervious->next = current->next;
                current->next->pervious = current->pervious;
                delete [] current;
            }
            
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
    for(Node *outerLoop = head; outerLoop != NULL; outerLoop = outerLoop->next) {
        for(Node *innerLoop = outerLoop->next; innerLoop != NULL; innerLoop = innerLoop->next) {
            if(outerLoop->value > innerLoop->value) {
                swap(&outerLoop->value, &innerLoop->value);
            }
        }
    }
}  

void reverse() {
    if(head == NULL) {
        return;
    }
    
    Node *node;

    while(head != NULL) {
        node = head->pervious;
        head->pervious = head->next;
        head->next = node;

        if(head->pervious == NULL) {
            return;
        }

        head = head->pervious;
    }
}

void printFront() {
    if(head == NULL) {
        puts("List is empty.");
        return;
    }

    for(Node *printNode = head; printNode != NULL; printNode = printNode->next) {
        printf("%d ", printNode->value);
    }
    putchar('\n');
}  

void printBack() {
    if(tail == NULL) {
        puts("List is empty.");
        return;
    }

    for(Node *printNode = tail; printNode != NULL; printNode = printNode->pervious) {
        printf("%d ", printNode->value);
    }
    putchar('\n');
}

void clear() {
    Node *temp;

    while(head) {
        temp = head;
        head = head->next;
        delete [] temp;
    }

    head = NULL;
}  

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
    
    clear();

    delete [] head;
    delete [] tail;
    return 0;
}