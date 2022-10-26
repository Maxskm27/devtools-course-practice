// Copyright 2022 Ryabtsev Maksim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Ryabtsev_Maksim_ComplexNumber_Test, DefaultConstr) {
  ComplexNumber number;
  ASSERT_EQ(number.getRe(), 0);
  ASSERT_EQ(number.getIm(), 0);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, TwoParamConstr) {
  ComplexNumber number(2.5, 5.0);
  ASSERT_EQ(number.getRe(), 2.5);
  ASSERT_EQ(number.getIm(), 5.0);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, CopyConstr) {
  ComplexNumber number(2.5, 5.0);
  ComplexNumber copy_number(number);
  ASSERT_EQ(copy_number.getRe(), 2.5);
  ASSERT_EQ(copy_number.getIm(), 5.0);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, AssignmentOper) {
  ComplexNumber number(2.5, 5.0);
  ComplexNumber copy_number;
  copy_number = number;
  ASSERT_EQ(copy_number.getRe(), 2.5);
  ASSERT_EQ(copy_number.getIm(), 5.0);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, GetRe) {
  ComplexNumber number(2.5, 5.0);
  ASSERT_EQ(number.getRe(), 2.5);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, GetIm) {
  ComplexNumber number(2.5, 5.0);
  ASSERT_EQ(number.getIm(), 5.0);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, SetRe) {
  ComplexNumber number(2.5, 5.0);
  number.setRe(-3.0);
  ASSERT_EQ(number.getRe(), -3.0);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, SetIm) {
  ComplexNumber number(2.5, 5.0);
  number.setIm(10.5);
  ASSERT_EQ(number.getIm(), 10.5);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, PlusOper) {
  ComplexNumber num_1(2.5, 5.0);
  ComplexNumber num_2(-3.0, 10.5);
  ComplexNumber num_3 = num_1 + num_2;
  ASSERT_EQ(num_3.getRe(), -0.5);
  ASSERT_EQ(num_3.getIm(), 15.5);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, MinusOper) {
  ComplexNumber num_1(2.5, 5.0);
  ComplexNumber num_2(-3.0, 10.5);
  ComplexNumber num_3 = num_1 - num_2;
  ASSERT_EQ(num_3.getRe(), 5.5);
  ASSERT_EQ(num_3.getIm(), -5.5);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, MultiplyOper) {
  ComplexNumber num_1(2.5, 5.0);
  ComplexNumber num_2(-3.0, 10.5);
  ComplexNumber num_3 = num_1 * num_2;
  ASSERT_EQ(num_3.getRe(), -60.0);
  ASSERT_EQ(num_3.getIm(), 11.25);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, DivisionOperThrow) {
  ComplexNumber num_1(2.5, 5.0);
  ComplexNumber num_2;
  ASSERT_ANY_THROW(num_1 / num_2);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, DivisionOper) {
  ComplexNumber num_1(2.5, 5.0);
  ComplexNumber num_2(-3.0, 10.5);
  ComplexNumber num_3 = num_1 / num_2;

  ASSERT_NEAR(num_3.getRe(), 0.37735, 0.00001);
  ASSERT_NEAR(num_3.getIm(), -0.34591, 0.00001);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, EqualsOper) {
  ComplexNumber num_1(2.5, 5.0);
  ComplexNumber num_2(2.5, 5.0);
  ASSERT_TRUE(num_1 == num_2);
}

TEST(Ryabtsev_Maksim_ComplexNumber_Test, NotEqualsOper) {
  ComplexNumber num_1(2.5, 5.0);
  ComplexNumber num_2(-3.0, 10.5);
  ASSERT_FALSE(num_1 == num_2);
}
