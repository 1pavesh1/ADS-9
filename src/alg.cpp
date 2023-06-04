// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
  BST <std::string> tree;
  std::ifstream file(filename);
 if (!file) {
   std::cout << "File error!" << std::endl;
   return tree;
 } else {
  if (!file) {
    std::cout << "File error!" << std::endl;
    return tree;
  } else {
     while (!file.eof()) {
     std::string temp = "";
     while(true) {
     while (true) {
       char ch;
       ch = file.get();
       if (ch >= 'a' && ch <= 'z') {
         temp += ch;
       } else if (ch >= 'A' && ch <= 'Z') {
           ch= tolower(ch);
           ch = tolower(ch);
           temp += ch;
                    } else {
                        break;
                     }
                }
                tree.add(temp);
        }
        return tree;
    }
}
