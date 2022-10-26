// Copyright 2022 Ryabtsev Maksim
#ifndef MODULES_RYABTSEV_M_CEASAR_CIPHER_INCLUDE_CEASAR_CIPHER_H_
#define MODULES_RYABTSEV_M_CEASAR_CIPHER_INCLUDE_CEASAR_CIPHER_H_

#include <string>
#include <vector>
using std::string;
using std::vector;

class CaesarCipher {
 public:
  string input;
  int offset;
  CaesarCipher();
  CaesarCipher(string input, int offset);
  string encode(string input, int offset);
  string decode(string input, int offset);

 private:
  const vector<string> alphabet = {"A", "B", "C", "D", "E", "F", "G", "H", "I",
                                   "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                                   "S", "T", "U", "V", "W", "X", "Y", "Z"};
};

#endif  // MODULES_RYABTSEV_M_CEASAR_CIPHER_INCLUDE_CEASAR_CIPHER_H_
