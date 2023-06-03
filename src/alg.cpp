// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
std::ifstream file(filename);
        std::string copy;
        std::string word;
        std::string clear;
        while (!file.eof())
        {
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
