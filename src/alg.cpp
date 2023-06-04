// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::string("ERROR!");
  }
  std::string word = "";
  BST<std::string> bst;
  while (!file.eof()) {
    word = "";
    while (1) {
      char symb = file.get();
      if ((symb >= 65 && symb <= 90) || (symb >= 97 && symb <= 122)) {
        word += tolower(symb);
      } else {
        break;
      }
    }
    bst.AddValue(word);
  }
  return bst;
}
