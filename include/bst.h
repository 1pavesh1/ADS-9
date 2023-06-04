// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template<typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node *left;
        Node *right;
    };
    Node* root;
    Node* addNode(Node *root, const T& value) {
        if (root == nullptr) {
            root = new Node;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->left = addNode(root->left, value);
        } else if (root->value < value) {
            root->right = addNode(root->right, value);
        } else {
            root->count++;
        }
        return root;
    }
    Node* searchNode(Node* root, const T& value) {
        if (root == nullptr || root->value == value) {
            return root;
        }
        if (root->value > value) {
            return searchNode(root->left, value);
        }
        return searchNode(root->right, value);
    }
    int depthTree(Node* root) {
        if (root == nullptr) return 0;
        return std::max(depthTree(root->left), depthTree(root->right)) + 1;
    }

 public:
    BST() : root(nullptr) {}
    int depth() {
        return depthTree(root) - 1;
    }
    int search(const T& value) {
        Node* i = searchNode(root, value);
        if (i != nullptr) {
            return i->count;
        } else {
            return  0;
        }
    }
    void add(const T& value) {
        root = addNode(root, value);
    }
};
#endif  // INCLUDE_BST_H_
