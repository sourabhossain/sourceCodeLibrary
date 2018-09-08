/**
 *  Name: Binary Search Tree
 *  Author Name: Sourav Hossain
 */ 

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

Node *get(int item) {
    Node *node = new Node();

    if(node == NULL) {
        puts("Error! Could not create a new node");
        exit(1);
    } 

    node->data = item;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
} // end get function

void addLeftChild(Node *node, Node *child) {
    node->left = child;

    if(child != NULL) {
        child->parent = node; 
    }
} // end addLeftChild function 

void addRightChild(Node *node, Node *child) {
    node->right = child;

    if(child != NULL) {
        child->parent = node;
    }
} // end addRightChild function

Node *insert(Node *root, int item) {
    Node *childNode = get(item); // go to get function

    if(root == NULL) {
        root = childNode;
    } else {
        Node *currentNode = root, *parentNode = NULL;

        while(currentNode != NULL) {
            parentNode = currentNode;

            if(item < currentNode->data) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }

        if(item < parentNode->data) {
            addLeftChild(parentNode, childNode); // go to addLeftChild function
        } else {
            addRightChild(parentNode, childNode); // go to addRightChild function
        }
    }

    return root;
} // end insert function

Node *search(Node *root, int item) {
    while(root != NULL) {
        if(root->data == item) {
            return root;
        }

        if(item < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return NULL;
} // end search function

Node *maximum(Node *root) {
    while(root->right != NULL) {
        root = root->right;
    }

    return root;
} // end maximum function

Node *minimum(Node *root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root;
} // end minimum function

Node *transplant(Node *root, Node *currentNode, Node *newNode) {
    if(currentNode == root) {
        root = newNode;
    } else if(currentNode == currentNode->parent->left) {
        addLeftChild(currentNode->parent, newNode);
    } else {
        addRightChild(currentNode->parent, newNode);
    }

    return root;
} // end transplant function

Node *erase(Node *root, Node *node) {
    if(node == NULL) {
        return root;
    }

    if(node->left == NULL) {
        root = transplant(root, node, node->right);
    } else if(node->right == NULL) {
        root = transplant(root, node, node->left);
    } else {
        Node *smallestNode = minimum(node->right);

        if(smallestNode->parent != node) {
            root = transplant(root, smallestNode, smallestNode->right);
            addRightChild(smallestNode, node->right);
        }

        root = transplant(root, node, smallestNode);
        addLeftChild(smallestNode, node->left);
    }
    
    delete [] node;
    return root;
} // end erase function

void preOrder(Node *printNode) {
    if(printNode == NULL) {
        return;
    }

    printf("%d ", printNode->data);
    preOrder(printNode->left);
    preOrder(printNode->right);
} // end preOrder function

void inOrder(Node *printNode) {
    if(printNode == NULL) {
        return;
    }
    
    inOrder(printNode->left);
    printf("%d ", printNode->data);
    inOrder(printNode->right);
} // end inOrder function

void postOrder(Node *printNode) {
    if(printNode == NULL) {
        return;
    }

    postOrder(printNode->left);
    postOrder(printNode->right);
    printf("%d ", printNode->data);
} // end postOrder function

void levelOrder(Node *printNode) {
    if(printNode == NULL) {
        return;
    }

    queue <Node*> q;
    q.push(printNode);

    while(!q.empty()) {
        Node *currentNode = q.front();
        q.pop();
        printf("%d ", currentNode->data);

        if(currentNode->left != NULL) {
            q.push(currentNode->left);
        }

        if(currentNode->right != NULL) {
            q.push(currentNode->right);
        }
    }
} // end levelOrder function

int main()
{
    Node *root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 17);
    root = insert(root, 3);
    root = insert(root, 12);
    root = insert(root, 19);
    root = insert(root, 7);
 
    // if(search(root, 100) != NULL) {
    //     puts("YES");
    // } else {
    //     puts("NO");
    // }    
    
    // printf("Maximum value is: %d\n", *maximum(root));
    // printf("Minimum value is: %d\n", *minimum(root));

    root = erase(root, search(root, 100)); 

    puts("Pre Order:");
    preOrder(root);
    putchar('\n');
    
    puts("\nIn Order:");
    inOrder(root);
    putchar('\n');
    
    puts("\nPost Order:");
    postOrder(root);
    putchar('\n');
    
    puts("\nLevel Order:");
    levelOrder(root);
    putchar('\n');

    delete [] root;
    return 0;
}