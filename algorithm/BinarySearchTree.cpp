#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node *newNode(int item) {
    Node *tmp = new Node;
    tmp->key = item;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

Node *insert(Node *node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

Node *deleteNode(Node *root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        }

        Node *succParent = root->right;
        Node *succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        succParent->left = succ->right;
        root->key = succ->key;
    }

    return root;
}

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 8);

    inorder(root);
    cout << "\n";

    root = deleteNode(root, 2);
    inorder(root);
    cout << "\n";

    root = deleteNode(root, 3);
    inorder(root);
    cout << "\n";

    root = deleteNode(root, 5);
    inorder(root);

    return 0;
}