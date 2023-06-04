// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cstdlib>
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
    std::string makeTree(const char* filename) {
        std::ifstream file(filename);
        std::string copy;
        std::string word;
        std::string clear;
        while (!file.eof()) {
            std::getline(file, copy);
            for (size_t i = 0; i < copy.size(); ++i) {
                if (copy[i] >= 65 && copy[i] <= 90 || copy[i] >= 97 && copy[i] <= 122) {
                    if (copy[i] >= 65 && copy[i] <= 90) {
                        word += copy[i] + 32;
                    } else {
                        word += copy[i];
                    }
                }
                if (copy[i + 1] == ' ' && word.size() == 1 || word.size() == 1 && i + 1 == copy.size()) {
                    word = clear;
                }
                if (copy[i] == ' ' && word != clear) {
                    word = clear;
                } else if (copy[i + 1] == ' ' && word != clear || i + 1 == copy.size() && word != clear || copy[i] == 39 && word != clear) {
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
                    if (i + 1 == copy.size()) {
                        word = clear;
                        break;
                    }
                }
            }
        }
        file.close();
        return word;
    }
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
    int height(node* root) {
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
