// Copyright 2022 Ryabtsev Maksim

#include <gtest/gtest.h>

#include <string>  // NOLINT

#include "include/ceasar_cipher.h"

TEST(CEASER_CIPHER_TEST, start) {
  CaesarCipher z;
  EXPECT_EQ(z.input, "");
}

TEST(CEASER_CIPHER_TEST, start_2) {
  CaesarCipher z;
  EXPECT_EQ(z.offset, 0);
}

TEST(CEASER_CIPHER_TEST, init) {
  CaesarCipher z("TEST", 3);
  EXPECT_EQ(z.input, "TEST");
}

TEST(CEASER_CIPHER_TEST, init_2) {
  CaesarCipher z("TEST", 3);
  EXPECT_EQ(z.offset, 3);
}

TEST(CEASER_CIPHER_TEST, FALL) {
  CaesarCipher z;
  string a = "";
  ASSERT_ANY_THROW(z.encode(a, 3));
}

TEST(CEASER_CIPHER_TEST, NO_FALL) {
  CaesarCipher z;
  string a = "TEST";
  ASSERT_NO_THROW((z.encode(a, 3)));
}

TEST(CEASER_CIPHER_TEST, decoding_NO_FALL) {
  CaesarCipher z;
  string a = "WHVW";
  ASSERT_NO_THROW((z.decode(a, 3)));
  EXPECT_EQ(z.decode(a, 3), "TEST");
}

TEST(CEASER_CIPHER_TEST, decoding_FALL) {
  CaesarCipher z;
  string a = "";
  ASSERT_ANY_THROW((z.decode(a, 3)));
}

TEST(CEASER_CIPHER_TEST, All_letters) {
  CaesarCipher z;
  string a = "QWERTYUIOASDFGHJKLZXCVBNM";
  EXPECT_EQ(z.encode(a, 3), "TZHUWBXLRDVGIJKMNOCAFYEQP");
}

TEST(CEASER_CIPHER_TEST, All_letters_2) {
  CaesarCipher z;
  string a = "TZHUWBXLRDVGIJKMNOCAFYEQP";
  EXPECT_EQ(z.decode(a, 3), "QWERTYUIOASDFGHJKLZXCVBNM");
}

TEST(CEASER_CIPHER_TEST, normal) {
  CaesarCipher z;
  string a = "TEST";
  EXPECT_EQ(z.encode(a, 3), "WHVW");
}

TEST(CEASER_CIPHER_TEST, change_step) {
  CaesarCipher z;
  string a = "TEST";
  EXPECT_EQ(z.encode(a, 2), "VGUV");
}

TEST(CEASER_CIPHER_TEST, change_step_2) {
  CaesarCipher z;
  string a = "TEST";
  EXPECT_EQ(z.encode(a, 5), "YJXY");
}

TEST(CEASER_CIPHER_TEST, with_space) {
  CaesarCipher z;
  string a = "HELLO WORLD";
  EXPECT_EQ(z.encode(a, 3), "KHOOR ZRUOG");
}

TEST(CEASER_CIPHER_TEST, lower) {
  CaesarCipher z;
  string a = "HeLlO WORLd";
  EXPECT_EQ(z.encode(a, 3), "KHOOR ZRUOG");
}

TEST(CEASER_CIPHER_TEST, decoding_without_space) {
  CaesarCipher z;
  string a = "WHVW";
  EXPECT_EQ(z.decode(a, 3), "TEST");
}

TEST(CEASER_CIPHER_TEST, decoding_change_step) {
  CaesarCipher z;
  string a = "VGUV";
  EXPECT_EQ(z.decode(a, 2), "TEST");
}

TEST(CEASER_CIPHER_TEST, decoding_change_step_2) {
  CaesarCipher z;
  string a = "YJXY";
  EXPECT_EQ(z.decode(a, 5), "TEST");
}

TEST(CEASER_CIPHER_TEST, decoding_with_space) {
  CaesarCipher z;
  string a = "KHOOR ZRUOG";
  EXPECT_EQ(z.decode(a, 3), "HELLO WORLD");
}

TEST(CEASER_CIPHER_TEST, decoding_lower) {
  CaesarCipher z;
  string a = "KhOOr zRUOg";
  EXPECT_EQ(z.decode(a, 3), "HELLO WORLD");
}
