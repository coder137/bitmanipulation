#include "unity.h"

#include "bit.h"

static uint32_t set;

void setUp() { set = 0; }
void tearDown() {}

void test_bit_set(void) {
  uint32_t value = 0;

  // Manual
  value = BIT_SET_1(set, 0);
  TEST_ASSERT_EQUAL_UINT32(value, 1);

  value = BIT_SET_1(set, 1);
  TEST_ASSERT_EQUAL_UINT32(value, 0x02);

  value = BIT_SET_1(set, 2);
  TEST_ASSERT_EQUAL_UINT32(value, 0x04);

  value = BIT_SET_1(set, 3);
  TEST_ASSERT_EQUAL_UINT32(value, 0x08);

  value = BIT_SET_1(set, 4);
  TEST_ASSERT_EQUAL_UINT32(value, 0x10);

  // Automated
  for (int i = 0; i < 32; i++) {
    value = BIT_SET_1(set, i);
    TEST_ASSERT_EQUAL_UINT32(value, (1 << i));
  }

  // Overflow will cause a -Wshift-count-overflow compile time error
  // BIT_SET(set, 32);
}

static void test_bit_set_n(uint8_t start_pos, uint8_t n, uint32_t actual) {
  uint32_t value = BIT_SET_N(set, start_pos, n);
  TEST_ASSERT_EQUAL_UINT32(value, actual);
}

void test_bit_set_n_different_bit_mask(void) {
  // Check Manually
  test_bit_set_n(0, 0, 0x00);
  test_bit_set_n(0, 1, 0x01);
  test_bit_set_n(0, 2, 0x03);
  test_bit_set_n(0, 3, 0x07);
  test_bit_set_n(0, 4, 0x0F);

  // Check automated
  for (int i = 0; i < 32; i++) {
    test_bit_set_n(0, i, BIT_MASK(i));
  }
}

void test_bit_set_n_different_start_position(void) {
  // Check Manually
  test_bit_set_n(0, 1, 0x01);
  test_bit_set_n(1, 1, 0x02);
  test_bit_set_n(2, 1, 0x04);
  test_bit_set_n(3, 1, 0x08);

  // Check automated
  for (int i = 0; i < 32; i++) {
    test_bit_set_n(i, 1, (1 << i));
  }
}

void test_bit_set_n_different_bit_mask_and_start_position(void) {
  // Start from position 1 for n bits
  test_bit_set_n(1, 2, 0b0110);
  test_bit_set_n(1, 3, 0b1110);
  test_bit_set_n(1, 4, 0b00011110);
  test_bit_set_n(1, 5, 0b00111110);
  test_bit_set_n(1, 6, 0b01111110);
  test_bit_set_n(1, 7, 0b11111110);

  // Start from position 2 for n bits
  test_bit_set_n(2, 2, 0b1100);
  test_bit_set_n(2, 3, 0b00011100);
  test_bit_set_n(2, 4, 0b00111100);
  test_bit_set_n(2, 5, 0b01111100);
  test_bit_set_n(2, 6, 0b11111100);

  // Start from position 3 for n bits
  test_bit_set_n(3, 2, 0b00011000);
  test_bit_set_n(3, 3, 0b00111000);
  test_bit_set_n(3, 4, 0b01111000);
  test_bit_set_n(3, 5, 0b11111000);

  // Start from position 4 for n bits
  test_bit_set_n(4, 2, 0b00110000);
  test_bit_set_n(4, 3, 0b01110000);
  test_bit_set_n(4, 4, 0b11110000);

  // Start from position 5 for n bits
  test_bit_set_n(5, 2, 0b01100000);
  test_bit_set_n(5, 3, 0b11100000);

  // Start from position 6 for n bits
  test_bit_set_n(6, 2, 0b11000000);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_bit_set);
  RUN_TEST(test_bit_set_n_different_bit_mask);
  RUN_TEST(test_bit_set_n_different_start_position);
  RUN_TEST(test_bit_set_n_different_bit_mask_and_start_position);
  return UNITY_END();
}
