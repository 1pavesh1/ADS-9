// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;

    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
    }

    std::string countwords;

    while (!file.eof()) {
        char ch = tolower(file.get());
        if (isalpha(ch)) {
            countwords = countwords + ch;
        } else {
            tree.add(countwords);
            countwords.clear();
        }
    }
    file.close();
    return tree;
}
