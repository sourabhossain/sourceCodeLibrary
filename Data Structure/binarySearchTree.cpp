/**
 *  Name: Binary Search Tree
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right; 
};

Node *get(int item) {
    Node *node = new Node();

    if(node == NULL) {
        puts("Error! Could not create a new node!");
        exit(1);
    }

    node->data = item;
    node->left = node->right = NULL;

    return node;
}

Node *maximum(Node *node) {
    while(node->right != NULL) {
        node = node->right;
    }

    return node;
}

Node *minimum(Node *node) {
    while(node->left != NULL) {
        node = node->left;
    }

    return node;
}

/**

Node *insert(Node *root, int item) {
    if(root == NULL) {
        return get(item);
    }

    if(item < root->data) {
        root->left = insert(root->left, item);
    } else {
        root->right = insert(root->right, item);
    }

    return root;
}  

*/ 

Node *insert(Node *root, int item) {
    Node *child = get(item);

    if(root == NULL) {
        return child;
    }

    Node *current = root, *parent = NULL;

    while(current != NULL) {
        parent = current;

        if(item < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if(item < parent->data) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    return root;
}

Node *erase(Node *node, int item) {
    if(node == NULL) {
        return node;
    }

    if(item < node->data) {
        node->left = erase(node->left, item);
    } else if(item > node->data) {
        node->right = erase(node->right, item);
    } else {
        if(node->left == NULL) {
            Node *child = node->right;
            delete [] node;
            return child;
        }

        if(node->right == NULL) {
            Node *child = node->left;
            delete [] node;
            return child;
        }

        Node *child = minimum(node->right);
        node->data = child->data;
        node->right = erase(node->right, child->data);
    }

    return node;
}

bool isBST(Node* node) {
    if(node == NULL) {
        return true;
    }

    stack<Node*> s;
    int previous = INT_MIN;
    bool has_previous = false;

    while(node != NULL || !s.empty()) {
        if(node != NULL) {
            s.push(node);
            node = node->left;
        } else {
            node = s.top();
            s.pop();

            if(has_previous && node->data <= previous) {
                return false;
            }

            previous = node->data;
            has_previous = true;
            node = node->right;
        }
    }

    return true;
}

bool search(Node *node, int item) {
    while(node != NULL) {
        if(node->data == item) {
            return true;
        }

        if(node->data > item) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    return false; 
}

int size(Node *node) {
    if(node == NULL) {
        return 0;
    }

    return size(node->left) + size(node->right) + 1;
}

int height(Node *node) {
    if(node == NULL) {
        return 0;
    }

    return max(height(node->left), height(node->right)) + 1;
}

void preOrder(Node *node) {
    if(node != NULL) {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(Node *node) {
    if(node != NULL) {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

void postOrder(Node *node) {
    if(node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->data);
    }
}

void labelOrder(Node *node) {
    if(node != NULL) {
        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node *current = q.front();
            q.pop();
            printf("%d ", current->data);

            if(current->left != NULL) {
                q.push(current->left);
            }

            if(current->right != NULL) {
                q.push(current->right);
            }
        }
    }
}

void ZigzagLabelOrder(Node *node) {
    if(node != NULL) {
        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node *current = q.front();
            q.pop();
            printf("%d ", current->data);

            if(current->right != NULL) {
                q.push(current->right);
            }

            if(current->left != NULL) {
                q.push(current->left);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    vector<int> data = {51, 64, 21, 77, 14, 4, 76, 20, 66, 91};
    int length = data.size();

    for(int i = 0; i < length; i++) {
        root = insert(root, data[i]);
    }

    root = erase(root, 14);
    root = erase(root, 20);
    root = erase(root, 66);

    puts("Pre-Order:");
    preOrder(root);

    puts("\n\nIn-Order:");
    inOrder(root);

    puts("\n\nPost-Order:");
    postOrder(root);

    puts("\n\nLabel-Order:");
    labelOrder(root);
    putchar('\n');

    puts("\n\nZigzag-Label-Order:");
    ZigzagLabelOrder(root);
    putchar('\n');

    printf("\nMaximum: %d\n", maximum(root)->data);
    printf("\nMinimum: %d\n", minimum(root)->data);
    printf("\nBoolean: %d\n", search(root, 77));
    printf("\nSize: %d\n", size(root));
    printf("\nHeight: %d\n", height(root));
    printf("\nisBST: %d\n", isBST(root));

    delete [] root;
    return 0;
}