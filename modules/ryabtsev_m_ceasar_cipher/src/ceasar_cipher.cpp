// Copyright 2022 Ryabtsev Maksim
#include "include/ceasar_cipher.h"

#include <string>
CaesarCipher::CaesarCipher() {
  input = "";
  offset = 0;
}

CaesarCipher::CaesarCipher(string input, int offset) {
  this->input = input;
  this->offset = offset;
}

string CaesarCipher::encode(string plain, int offset) {
  if (plain.empty()) throw 1;
  int len = plain.size();
  string result;
  for (int i = 0; i < len; i++) {
    if (isalpha(plain[i])) {
      int num = toupper(plain[i]) - 'A';
      int nxt = (num + offset + 26) % 26;
      result += static_cast<char>('A' + nxt);
    } else {
      string s;
      s = plain[i];
      result.append(s);
    }
  }
  return result;
}
string CaesarCipher::decode(string cipher, int offset) {
  if (cipher.empty()) throw 1;
  int len = cipher.size();
  string result;
  for (int i = 0; i < len; i++) {
    if (isalpha(cipher[i])) {
      int num = toupper(cipher[i]) - 'A';
      int nxt = (num - offset + 26) % 26;
      result += static_cast<char>('A' + nxt);
    } else {
      string s;
      s = cipher[i];
      result.append(s);
    }
  }
  return result;
}
