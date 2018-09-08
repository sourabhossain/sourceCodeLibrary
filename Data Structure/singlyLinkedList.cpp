/**
 *  Name: Singly Linked List
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next;
};

Node *head = NULL;

// all function prototype 
Node *get(int);
void pushFront(int);
void popFront();
void pushBack(int);
void popBack();
void insert(int, int);
void erase(int);
bool search(int);
int count(int);
int size();
bool empty();
void reverse();
void sort();
void print();
void clear();

int main()
{
    pushBack(10);
	pushFront(5);
	pushBack(15);
	pushBack(20);
    pushBack(10);

	reverse(); 

    insert(10, 5);
    erase(15);
    erase(10);

    erase(5);
    insert(5, 100);

    insert(5, 200);

    reverse();

    sort();

    reverse();

    cout << size() << endl;
    cout << search(100) << endl;

	//print();

	clear();
	return 0;
}

Node *get(int item) {
    Node *node = new Node();

    if(node == NULL) {
        puts("Error! Could not create a new node.");
        exit(1);
    }

    node->value = item;
    node->next = NULL;

    return node;
} // end get function

void pushFront(int value) {
    Node *node = get(value); // go to get function
    node->next = head;
    head = node;
} // end pushFront function

void popFront() {
    if(head == NULL) {
        puts("List is empty!");
        return;
    }

    Node *node = head->next;
    delete [] head;
    head = node;
} // end popFront function

void pushBack(int value) {
    Node *node = get(value); // go to get function

    if(head == NULL) {
        head = node;
    } else {
        Node *iterator = head;

        while(iterator->next != NULL) {
            iterator = iterator->next;
        }

        iterator->next = node;
    }
} // end pushBack function

void popBack() {
    if(head == NULL) {
        puts("List is empty!");
        return;
    }

    Node *iterator = head, *previous = NULL;

    while(iterator->next != NULL) {
        previous = iterator;
        iterator = iterator->next;
    }

    if(previous == NULL) {
        delete [] head;
        head = NULL;
    } else {
        previous->next = NULL;
        delete [] iterator;
        iterator = previous;
    }
} // end popBack function

void insert(int key, int item) {
    if(head == NULL) {
        puts("List is empty!");
        return;
    }

    for(Node *iterator = head, *previous = NULL; iterator != NULL; iterator = iterator->next) {
        if(iterator->value == key) {
            if(previous == NULL) {
                pushFront(item); // go to pushFront function
            } else {
                previous->next = get(item); // go to get function
                previous->next->next = iterator;
                iterator = previous;
            }
            return;
        }

        previous = iterator;
    }

    pushBack(item); // go to pushBack function
} // end insert function

void erase(int item) {
    if(head == NULL) {
        puts("List is empty!");
        return;
    }

    for(Node *iterator = head, *previous = NULL; iterator != NULL; iterator = iterator->next) {
        if(iterator->value == item) {
            if(previous == NULL) {
                popFront(); // go to popFront function
            } else {
                previous->next = iterator->next;
                delete [] iterator;
                iterator = previous;
            }
            return;
        }

        previous = iterator;
    }
} // end erase function

bool search(int item) {
    if(head == NULL) {
        return false;
    }

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        if(item == iterator->value) {
            return true;
        }
    }

    return false;
} // end search function

int count(int item) {
    if(head == NULL) {
        return 0;
    }

    int counter = 0;

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        if(item == iterator->value) {
            counter += 1;
        }
    }

    return counter;
} // end count function

int size() {
    if(head == NULL) {
        return 0;
    }

    int counter = 0;

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        counter += 1;
    }

    return counter;
} // end size function

bool empty() {
    if(head == NULL) {
        return true;
    }

    return false;
} // end empty function

void reverse() {
    if(head == NULL) {
        puts("List is empty!");
        return;
    }

    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
} // end reverse function

void swap(int *first, int *second) {
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
} // end swap function

void sort() {
	if(head == NULL) {
		puts("List is empty!");
		return;
	}

    for(Node *outerLoop = head; outerLoop != NULL; outerLoop = outerLoop->next) {
        for(Node *innerLoop = outerLoop->next; innerLoop != NULL; innerLoop = innerLoop->next) {
            if(outerLoop->value > innerLoop->value) {
                swap(&outerLoop->value, &innerLoop->value);
            }
        }
    }
} // end sort function

void print() {
	if(head == NULL) {
		puts("List is empty!");
	}

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        printf("%d ", iterator->value);
    }
    putchar('\n');
} // end print function

void clear() {
    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        delete [] iterator;
    }
} // end clear function