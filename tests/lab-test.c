#include <stdlib.h>
#include <stdio.h>
#include "harness/unity.h"
#include "../src/lab.h"


void setUp(void) {
  printf("Setting up tests...\n");
}

void tearDown(void) {
  printf("Tearing down tests...\n");
}

void test_add(void) {
  TEST_ASSERT_EQUAL(8, add(5, 3));
  TEST_ASSERT_EQUAL(-2, add(-5, 3));
  TEST_ASSERT_EQUAL(0, add(0, 0));
}

void test_subtract(void) {
  TEST_ASSERT_EQUAL(2, subtract(5, 3));
  TEST_ASSERT_EQUAL(-8, subtract(-5, 3));
  TEST_ASSERT_EQUAL(0, subtract(0, 0));
}

void test_product(void) {
  TEST_ASSERT_EQUAL(15, product(5, 3));
  TEST_ASSERT_EQUAL(-15, product(-5, 3));
  TEST_ASSERT_EQUAL(0, product(0, 5));
}

void test_incorrect_sum(void) {
  TEST_ASSERT_FALSE(incorrectSum(5,3) == 8);
  TEST_ASSERT_FALSE(incorrectSum(-5,3) == -2);
  TEST_ASSERT_FALSE(incorrectSum(2,1)==3);
}

void test_get_greeting(void) {
  char *greeting = get_greeting("Alice");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, Alice!", greeting);
  free(greeting); // Free the allocated memory for the greeting

  greeting = get_greeting(NULL);
  TEST_ASSERT_NULL(greeting);

  greeting = get_greeting("");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, !", greeting);
  free(greeting);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_get_greeting);
  RUN_TEST(test_add);
  RUN_TEST(test_subtract);
  RUN_TEST(test_product);
  RUN_TEST(test_incorrect_sum);
  return UNITY_END();
}
