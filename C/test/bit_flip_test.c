#include "unity.h"

#include "bit.h"

void setUp() {}
void tearDown() {}

void test_bit_flip(void) {
  uint32_t value = 0x11;

  // 1 -> 0
  BIT_FLIP(value, 0);
  TEST_ASSERT_EQUAL_UINT32(value, 0x10);

  // 0 -> 1
  BIT_FLIP(value, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x12);

  // 1 -> 0
  BIT_FLIP(value, 4);
  TEST_ASSERT_EQUAL_UINT32(value, 0x02);

  // 0 -> 1
  BIT_FLIP(value, 5);
  TEST_ASSERT_EQUAL_UINT32(value, 0x22);
}

void test_bit_flip_n_single(void) {
  uint32_t value = 0x11;

  // 1 -> 0
  BIT_FLIP_N(value, 0, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x10);

  // 0 -> 1
  BIT_FLIP_N(value, 1, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x12);

  // 1 -> 0
  BIT_FLIP_N(value, 4, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x02);

  // 0 -> 1
  BIT_FLIP_N(value, 5, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x22);
}

static void bit_flip_n_test(uint32_t value, uint8_t start_pos, uint8_t n,
                            uint32_t expected) {
  BIT_FLIP_N(value, start_pos, n);
  TEST_ASSERT_EQUAL_UINT32(value, expected);
}

void test_bit_flip_n_different_bit_mask(void) {
  // 0
  uint32_t value = 0x00;
  bit_flip_n_test(value, 0, 2, 0x03);

  value = 0x00;
  bit_flip_n_test(value, 0, 3, 0x07);

  value = 0x00;
  bit_flip_n_test(value, 0, 4, 0x0F);

  // 1
  value = 0x01;
  bit_flip_n_test(value, 0, 2, 0x02);

  value = 0x01;
  bit_flip_n_test(value, 0, 3, 0x06);

  value = 0x01;
  bit_flip_n_test(value, 0, 4, 0x0E);

  // 2
  value = 0x02;
  bit_flip_n_test(value, 0, 2, 0x01);

  value = 0x02;
  bit_flip_n_test(value, 0, 3, 0x05);

  value = 0x02;
  bit_flip_n_test(value, 0, 4, 0x0D);

  // 3
  value = 0x03;
  bit_flip_n_test(value, 0, 2, 0x00);

  value = 0x03;
  bit_flip_n_test(value, 0, 3, 0x04);

  value = 0x03;
  bit_flip_n_test(value, 0, 4, 0x0C);

  // 4
  value = 0x04;
  bit_flip_n_test(value, 0, 2, 0x07);

  value = 0x04;
  bit_flip_n_test(value, 0, 3, 0x03);

  value = 0x04;
  bit_flip_n_test(value, 0, 4, 0x0B);
}

void test_bit_flip_n_different_start_position(void) {
  // 0
  uint32_t value = 0x00;
  bit_flip_n_test(value, 1, 3, 0x0E);

  value = 0x00;
  bit_flip_n_test(value, 2, 3, 0x1C);

  value = 0x00;
  bit_flip_n_test(value, 3, 3, 0x38);

  // 1
  value = 0x10;
  bit_flip_n_test(value, 1, 3, 0x1E);

  value = 0x10;
  bit_flip_n_test(value, 2, 3, 0x0C);

  value = 0x10;
  bit_flip_n_test(value, 3, 3, 0x28);

  // 2
  value = 0x20;
  bit_flip_n_test(value, 1, 3, 0x2E);

  value = 0x20;
  bit_flip_n_test(value, 2, 3, 0x3C);

  value = 0x20;
  bit_flip_n_test(value, 3, 3, 0x18);

  // 3
  value = 0x30;
  bit_flip_n_test(value, 1, 3, 0x3E);

  value = 0x30;
  bit_flip_n_test(value, 2, 3, 0x2C);

  value = 0x30;
  bit_flip_n_test(value, 3, 3, 0x08);

  // 4
  value = 0x40;
  bit_flip_n_test(value, 1, 3, 0x4E);

  value = 0x40;
  bit_flip_n_test(value, 2, 3, 0x5C);

  value = 0x40;
  bit_flip_n_test(value, 3, 3, 0x78);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_bit_flip);
  RUN_TEST(test_bit_flip_n_single);
  RUN_TEST(test_bit_flip_n_different_bit_mask);
  RUN_TEST(test_bit_flip_n_different_start_position);
  return UNITY_END();
}
