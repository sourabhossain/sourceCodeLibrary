/**
 *  Name: Singly Linked List
 *  Author Name: Sourab Hossain
 */

#include <bits/stdc++.h>

using namespace std;
 
struct Node {
	int value;
	Node *next;
};

Node *head = NULL;

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
void reverse(Node*);
void reverse_print(Node*);
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

	print();
    putchar('\n');

    reverse_print(head);
    putchar('\n');

	clear();

    delete [] head;
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
}

void pushFront(int value) {
    Node *node = get(value);  
    node->next = head;
    head = node;
}  

void popFront() {
    if(head == NULL) {
        puts("List is empty!");
        return;
    }

    Node *node = head->next;
    delete [] head;
    head = node;
}  

void pushBack(int value) {
    Node *node = get(value);  

    if(head == NULL) {
        head = node;
    } else {
        Node *iterator = head;

        while(iterator->next != NULL) {
            iterator = iterator->next;
        }

        iterator->next = node;
    }
}  

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
}  

/**

void insert(int item, int position) {
    Node *iterator = head, *previous = NULL;

    while(iterator != NULL && --position) {
        previous = iterator;
        iterator = iterator->next;
    }

    if(previous == NULL) {
        pushFront(item);  
    } else {
        Node *node = get(item);  

        node->next = iterator;
        previous->next = node;
        previous = node;
    }
}  

**/

void insert(int key, int item) {
    if(head == NULL) {
        puts("List is empty!");
        return;
    }

    for(Node *iterator = head, *previous = NULL; iterator != NULL; iterator = iterator->next) {
        if(iterator->value == key) {
            if(previous == NULL) {
                pushFront(item);  
            } else {
                previous->next = get(item); 
                previous->next->next = iterator;
                iterator = previous;
            }
            return;
        }

        previous = iterator;
    }

    pushBack(item);  
} 

/**

void erase(int index) {
    if(node == NULL) {
        return;
    }

    Node *node = head;

    if(index == 1) {
        head = node->next;
        delete [] node;
        return;
    }

    for(int i = 2; i < index; i++) {
        if(node->next == NULL) {
            return;
        }

        node = node->next;
    }

    Node *temp = node->next;
    node->next = temp->next;
    delete [] temp;
}

**/

void erase(int item) {
    if(head == NULL) {
        puts("List is empty!");
        return;
    }

    for(Node *iterator = head, *previous = NULL; iterator != NULL; iterator = iterator->next) {
        if(iterator->value == item) {
            if(previous == NULL) {
                popFront();  
            } else {
                previous->next = iterator->next;
                delete [] iterator;
                iterator = previous;
            }
            return;
        }

        previous = iterator;
    }
}  

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
}  

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
}  

int size() {
    if(head == NULL) {
        return 0;
    }

    int counter = 0;

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        counter += 1;
    }

    return counter;
}  

bool empty() {
    if(head == NULL) {
        return true;
    }

    return false;
}  

void reverse() {
    if(head == NULL) {
        puts("List is empty!");
        return;
    }

    Node *current = head;
    Node *previous = NULL, *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
} 

void reverse(Node *node) {
    if(node->next == NULL) {
        head = node;
        return;
    }

    reverse(node->next);
    Node *temp = node->next;
    temp->next = node;
    node->next = NULL;
} 

void reverse_print(Node* node) {
    if(node == NULL) {
        return;
    }

    reverse_print(node->next);
    printf("%d ", node->value);
}

/**

Node *merge(Node *l, Node *ll) {
    Node *node = get(-1);
    Node *current = node;

    while(l && ll) {
        if(l->value > ll->value) {
            current->next = ll;
            ll = ll->next;
        } else {
            current->next = l;
            l = l->next;
        }

        current = current->next;
    }

    current->next = (l)? l : ll;
    return node->next;
}

Node *sort(Node *node) {
    if(!node || !node->next) {
        return node;
    }

    Node *fast = head, *slow = head, *pre = head;

    while(fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    pre->next = NULL;
    return merge(sort(head), sort(slow)); 
}

**/

void swap(int *first, int *second) {
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
}  

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
}  

void removeDuplicates() {
    if(head == NULL) {
        return;
    }

    sort();
    Node *current = head, *next_next;

    while(current->next != NULL) {
        if(current->value == current->next->value) {
            next_next = current->next->next;
            delete [] current->next;
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}

void print() {
	if(head == NULL) {
		puts("List is empty!");
	}

    for(Node *iterator = head; iterator != NULL; iterator = iterator->next) {
        printf("%d ", iterator->value);
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