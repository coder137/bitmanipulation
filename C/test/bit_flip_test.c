#include "unity.h"

#include "bit.h"

void setUp() {}
void tearDown() {}

void test_bit_flip(void) {
  uint32_t flip = 0x11;
  uint32_t value = 0;

  value = BIT_FLIP_1(flip, 0);
  TEST_ASSERT_EQUAL_UINT32(value, 0x10);

  value = BIT_FLIP_1(flip, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x13);

  value = BIT_FLIP_1(flip, 4);
  TEST_ASSERT_EQUAL_UINT32(value, 0x01);

  value = BIT_FLIP_1(flip, 5);
  TEST_ASSERT_EQUAL_UINT32(value, 0x31);
}

void test_bit_flip_n_single(void) {
  uint32_t flip = 0x11;
  uint32_t value = 0;

  value = BIT_FLIP_N(flip, 0, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x10);

  value = BIT_FLIP_N(flip, 1, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x13);

  value = BIT_FLIP_N(flip, 4, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x01);

  value = BIT_FLIP_N(flip, 5, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x31);
}

static void bit_flip_n_test(uint32_t flip, uint8_t start_pos, uint8_t n,
                            uint32_t expected) {
  uint32_t value = BIT_FLIP_N(flip, start_pos, n);
  TEST_ASSERT_EQUAL_UINT32(value, expected);
}

void test_bit_flip_n_different_bit_mask(void) {
  // 0
  uint32_t value = 0x00;
  bit_flip_n_test(value, 0, 2, 0x03);
  bit_flip_n_test(value, 0, 3, 0x07);
  bit_flip_n_test(value, 0, 4, 0x0F);

  // 1
  value = 0x01;
  bit_flip_n_test(value, 0, 2, 0x02);
  bit_flip_n_test(value, 0, 3, 0x06);
  bit_flip_n_test(value, 0, 4, 0x0E);

  // 2
  value = 0x02;
  bit_flip_n_test(value, 0, 2, 0x01);
  bit_flip_n_test(value, 0, 3, 0x05);
  bit_flip_n_test(value, 0, 4, 0x0D);

  // 3
  value = 0x03;
  bit_flip_n_test(value, 0, 2, 0x00);
  bit_flip_n_test(value, 0, 3, 0x04);
  bit_flip_n_test(value, 0, 4, 0x0C);

  // 4
  value = 0x04;
  bit_flip_n_test(value, 0, 2, 0x07);
  bit_flip_n_test(value, 0, 3, 0x03);
  bit_flip_n_test(value, 0, 4, 0x0B);
}

void test_bit_flip_n_different_start_position(void) {
  // 0
  uint32_t value = 0x00;
  bit_flip_n_test(value, 1, 3, 0x0E);
  bit_flip_n_test(value, 2, 3, 0x1C);
  bit_flip_n_test(value, 3, 3, 0x38);

  // 1
  value = 0x10;
  bit_flip_n_test(value, 1, 3, 0x1E);
  bit_flip_n_test(value, 2, 3, 0x0C);
  bit_flip_n_test(value, 3, 3, 0x28);

  // 2
  value = 0x20;
  bit_flip_n_test(value, 1, 3, 0x2E);
  bit_flip_n_test(value, 2, 3, 0x3C);
  bit_flip_n_test(value, 3, 3, 0x18);

  // 3
  value = 0x30;
  bit_flip_n_test(value, 1, 3, 0x3E);
  bit_flip_n_test(value, 2, 3, 0x2C);
  bit_flip_n_test(value, 3, 3, 0x08);

  // 4
  value = 0x40;
  bit_flip_n_test(value, 1, 3, 0x4E);
  bit_flip_n_test(value, 2, 3, 0x5C);
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
