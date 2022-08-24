#include <bits/stdc++.h>

using namespace std;

struct node {
    bool endmark;
    node* next[26 + 1];
    node() {
        endmark = false;

        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
} *root;

void insert(char* str, int length) {
    node* current = root;

    for (int i = 0; i < length; i++) {
        int id = str[i] - 'a';

        if (current->next[id] == NULL) {
            current->next[id] = new node();
        }

        current = current->next[id];
    }

    current->endmark = 1;
}

bool search(char* str, int length) {
    node* current = root;

    for (int i = 0; i < length; i++) {
        int id = str[i] - 'a';

        if (current->next[id] == NULL) {
            return false;
        }

        current = current->next[id];
    }

    return current->endmark;
}

void remove(node* current) {
    for (int i = 0; i < 26; i++) {
        if (current->next[i]) {
            remove(current->next[i]);
        }
    }

    delete (current);
}

int main()
{
    root = new node();
    int num_word;

    puts("ENTER NUMBER OF WORDS");
    cin >> num_word;

    for (int i = 1; i <= num_word; i++) {
        char str[50];
        scanf("%s", str);
        insert(str, strlen(str));
    }

    int query;

    puts("ENTER NUMBER OF QUERY");
    cin >> query;

    for (int i = 1; i <= query; i++) {
        char str[50];
        scanf("%s", str);

        if (search(str, strlen(str)))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }

    remove(root);
    return 0;
}
