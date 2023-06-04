// Copyright 2021 NNTU-CS
#include  <cstdlib>
#include  <fstream>
#include  "bst.h"
#include  <fstream> 

BST<std::string> makeTree(const char* filename) {
    BST<std::string> bst;
    std::ifstream file(filename);
    std::string output;
    while (!file.eof()) {
        char str = file.get();
        if (str >= 65 && str <= 90) {
            str += 32;
            output += str;
            continue;
        }
        if (str >= 97 && str <= 122) {
            output += str;
        } else {
            if (!output.empty()) {
                bst.addVal(output);
            }
            output.clear();
        }
    }
    bst.addVal(output);
    file.close();
    return bst;
}
