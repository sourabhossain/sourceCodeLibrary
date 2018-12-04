/**
 *  Name: AVL Tree
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    int height;
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
    node->height = 1;

    return node;
}

int height(Node *node) {
	if(node == NULL) {
		return 0;
	}

	return node->height;
}

int getBalance(Node *node) {
	if(node == NULL) {
		return 0;
	}

	return height(node->left) - height(node->right);
}

Node *leftRotate(Node *node) {
	Node *right = node->right;
	Node *left = right->left;

	right->left = node;
	node->right = left;

	node->height = max(height(node->left), height(node->right));
	right->height = max(height(right->left), height(right->right));

	return right; 
}

Node *rightRotate(Node *node) {
	Node *left = node->left;
	Node *right = left->right;

	left->right = node;
	node->left = right;

	node->height = max(height(node->left), height(node->right));
	left->height = max(height(left->left), height(left->right));

	return left;
}

Node *insert(Node *node, int item) {
	if(node == NULL) {
		return get(item);
	}

	if(item < node->data) {
		node->left = insert(node->left, item);
	} else if(item > node->data) {
		node->right = insert(node->right, item);
	} else {
		return node;
	}

	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);

	if(balance > 1 && item < node->left->data) {
		return rightRotate(node);
	}

	if(balance < -1 && item > node->right->data) {
		return leftRotate(node);
	}

	if(balance > 1 && item > node->left->data) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if(balance > 1 && item < node->right->data) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	} 

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

Node *erase(Node *root, int item) {
	if(root == NULL) {
		return root;
	}

	if(item < root->data) {
		root->left = erase(root->left, item);
	} else if(item > root->data) {
		root->right = erase(root->right, item);
	} else {
		if((root->left == NULL) || (root->right == NULL)) {
			Node *node = (root->left != NULL)? root->left : root->right;

			if(node == NULL) {
				node = root;
				root = NULL;
			} else {
				*root = *node;
			}

			delete [] node;
		} else {
			Node *node = minimum(root->right);
			root->data = node->data;
			root->right = erase(root->right, node->data);
		}
	}

	if(root == NULL) {
		return root;
	}

	root->height = 1 + max(height(root->left), height(root->right));
	int balance = getBalance(root);

	if(balance > 1 && item < root->left->data) {
		return rightRotate(root);
	}

	if(balance < -1 && item > root->right->data) {
		return leftRotate(root);
	}

	if(balance > 1 && item > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if(balance > 1 && item < root->right->data) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	} 

	return root;
}

bool search(Node *node, int item) {
	while(node != NULL) {
		if(node->data == item) {
			return true;
		}

		node = (node->data > item)? node->left : node->right;
	}

	return false;
}

int size(Node *node) {
	if(node == NULL) {
		return 0;
	}

	return size(node->left) + size(node->right) + 1;
}

void preOrder(Node *node) {
	if(node != NULL) {
		printf("%d\n", node->data);
		preOrder(node->left);
		preOrder(node->right);
	}
} 

void inOrder(Node *node) {
	if(node != NULL) {
		inOrder(node->left);
		printf("%d\n", node->data);
		inOrder(node->right);
	}
}

void postOrder(Node *node) {
	if(node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		printf("%d\n", node->data);
	}
}

void labelOrder(Node *node) {
	if(node != NULL) {
		queue<Node*> q;
		q.push(node);

		while(!q.empty()) {
			Node *current = q.front();
			q.pop();
			printf("%d\n", current->data);

			if(current->left != NULL) {
				q.push(current->left);
			}

			if(current->right != NULL) {
				q.push(current->right);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 35);
    root = insert(root, 25);
    root = insert(root, 15);

    root = erase(root, 10);
    root = erase(root, 25);

    preOrder(root);

    delete [] root;
	return 0;
}