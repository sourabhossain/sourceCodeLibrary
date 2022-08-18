#include <bits/stdc++.h>

using namespace std;

struct Node {
    string key;
    string value;
    Node* prev;
    Node* next;

    Node() {
        prev = NULL;
        next = NULL;
    }

    Node(string _key, string _value) {
         key = _key;
         value = _value;
         Node();
    }
};

struct DoublyList {
    Node* head;
    Node* tail;

    DoublyList() {
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    void erase(Node *curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    void insertHead(Node* curr) {
        Node* temp = head->next;
        head->next = curr;
        curr->next = temp;
        temp->prev = curr;
        curr->prev = head;
    }

    string popTail() {
        Node* last = tail->prev;
        string key = last->key;
        last->prev->next = tail;
        tail->prev = last->prev;
        return key;
    }
};

class LRUCache {
private:
    int capacity;
    map<string, Node*> cache;
    DoublyList *list;

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        list = new DoublyList();
    }

    string get(string key) {
        if (cache.find(key) == cache.end()) {
            return "NOT FOUND";
        }

        Node *curr = cache[key];
        list->erase(curr);
        list->insertHead(curr);

        return curr->value;
    }

    void put(string key, string value) {
        Node* newNode = new Node(key, value);

        if (cache.find(key) != cache.end()) { // Found in hashmap
            Node *curr = cache[key];
            curr->value = value;

            list->erase(curr);
            list->insertHead(curr);
        } else {
            cache[key] = newNode;
            list->insertHead(newNode);

            if (cache.size() > capacity) {
                string key = list->popTail();
                cache.erase(key);
            }
        }
    }
};

int main()
{
    LRUCache cache(2);

    cache.put("name", "Sourab Hossain");
    cache.put("univercity", "Southeast University");
    cache.put("deperment", "CSE");

    cout << cache.get("name") << endl;
    cout << cache.get("deperment") << endl;

    return 0;
}
