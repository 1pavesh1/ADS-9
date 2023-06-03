// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
template <typename T>
class BST {
private:
    struct node {
        T word;
        int count;
        node *left, *right;
    };
    node *root;
    int Depth;

public:
    BST() {
        root = nullptr;
        Depth = 0;
    }
    BST <std::string> makeTree(const char* filename);
    node* addNode(node *root, const T& word) {
        if (root == nullptr) {
            root = new node;
            root->word = word;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->word > word) {
            root->left = addNode(root->left, word);
        } else if (root->word < word) {
            root->right = addNode(root->right, word);
        } else if (root->word == word) {
            root->count += 1;
        }
        return root;
    }
    int search(std::string word) {
        if (root == nullptr) {
            return 0;
        } else {
            if (root->word == word) {
                return root->count;
            } else {
                while (root->word != word) {
                    if (root->word > word) {
                        root = root->left;
                    } else if (root->word < word) {
                        root = root->right;
                    }
                }
                return root->count;
            }
        }
    }
    int height(node* root)
    {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }
    int depth() {
        if (root == nullptr) {
            return 0;
        } else {
            Depth += 1 + std::max(height(root->left), height(root->right));
            return Depth - 2;
        }
    }
    ~BST() {
        delete root;
    }
};
#endif  // INCLUDE_BST_H_
