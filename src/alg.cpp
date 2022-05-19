// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  BST<std::string> tree;
  std::string w, line;
  while (!file.eof()) {
    file >> w;
    int x = 0;
    while (x < w.length()) {
      int y = 0;
      while ((w[x] >= 'a' && w[x] <= 'z' ||
              w[x] >= 'A' && w[x] <= 'Z') && x < w.length()) {
        if (w[x] >= 'A' && w[x] <= 'Z')
          w[x] += 32;
        line += w[x];
        y++;
        x++;
      }
      if (y != 0) {
        tree.add(line);
        line = "";
      } else {
        x++;
      }
    }
  }
  return tree;
}
