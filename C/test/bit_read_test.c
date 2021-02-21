#include "unity.h"

#include "bit.h"

void setUp() {}
void tearDown() {}

void test_bit_read(void) {
  uint32_t value = 0b0100;
  TEST_ASSERT_EQUAL_UINT8(BIT_READ_1(value, 0), 0);
  TEST_ASSERT_EQUAL_UINT8(BIT_READ_1(value, 2), 1);
}

void test_bit_read_n_single(void) {
  uint32_t value = 0b0110;
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 0, 1), 0);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 1, 1), 1);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 2, 1), 1);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 3, 1), 0);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 4, 1), 0);
}

void test_bit_read_n_multiple(void) {
  uint32_t value = 0b0110;
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 0, 3), 6);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 1, 2), 3);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 2, 2), 1);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 3, 2), 0);

  value = 0b1000;
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 0, 3), 0);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 0, 4), 8);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 1, 2), 0);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 1, 3), 4);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 2, 2), 2);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 3, 2), 1);

  value = 0b1100;
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 0, 3), 4);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 0, 4), 12);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 1, 2), 2);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 1, 3), 6);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 2, 2), 3);
  TEST_ASSERT_EQUAL_UINT32(BIT_READ_N(value, 3, 2), 1);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_bit_read);
  RUN_TEST(test_bit_read_n_single);
  RUN_TEST(test_bit_read_n_multiple);
  return UNITY_END();
}
