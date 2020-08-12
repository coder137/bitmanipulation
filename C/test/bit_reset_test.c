#include "unity.h"

#include "bit.h"

static uint32_t reset;

void setUp() { reset = ~0; }
void tearDown() {}

void test_bit_reset(void) {
  uint32_t value = 0;

  // Check manually
  value = BIT_RESET(reset, 0);
  TEST_ASSERT_EQUAL_UINT32(value, 0xFFFFFFFE);

  value = BIT_RESET(reset, 3);
  TEST_ASSERT_EQUAL_UINT32(value, 0xFFFFFFF7);

  // Check automated
  for (int i = 0; i < 32; i++) {
    value = BIT_RESET(reset, i);
    TEST_ASSERT_EQUAL_UINT32(value, ~(1 << i));
  }
}

static void test_bit_reset_n(uint8_t start_pos, uint8_t n, uint32_t actual) {
  uint32_t value = BIT_RESET_N(reset, start_pos, n);
  TEST_ASSERT_EQUAL_UINT32(value, actual);
}

void test_bit_reset_n_different_bit_mask(void) {
  // Check Manually
  test_bit_reset_n(0, 0, 0xFFFFFFFF);
  test_bit_reset_n(0, 1, 0xFFFFFFFE);
  test_bit_reset_n(0, 2, 0xFFFFFFFC);
  test_bit_reset_n(0, 3, 0xFFFFFFF8);
  test_bit_reset_n(0, 4, 0xFFFFFFF0);

  // Check automated
  for (int i = 0; i < 32; i++) {
    test_bit_reset_n(0, i, ~BIT_MASK(i));
  }
}

void test_bit_reset_n_different_start_position(void) {
  // Check Manually
  test_bit_reset_n(0, 1, 0xFFFFFFFE);
  test_bit_reset_n(1, 1, 0xFFFFFFFD);
  test_bit_reset_n(2, 1, 0xFFFFFFFB);
  test_bit_reset_n(3, 1, 0xFFFFFFF7);
  test_bit_reset_n(4, 1, 0xFFFFFFEF);

  // Check automated
  for (int i = 0; i < 32; i++) {
    test_bit_reset_n(i, 1, ~(1 << i));
  }
}

void test_bit_reset_n_different_bit_mask_and_start_position(void) {
  // Start from position 1 for n bits
  test_bit_reset_n(1, 2, 0xFFFFFFF9);
  test_bit_reset_n(1, 3, 0xFFFFFFF1);
  test_bit_reset_n(1, 4, 0xFFFFFFE1);
  test_bit_reset_n(1, 5, 0xFFFFFFC1);
  test_bit_reset_n(1, 6, 0xFFFFFF81);
  test_bit_reset_n(1, 7, 0xFFFFFF01);

  // Start from position 2 for n bits
  test_bit_reset_n(2, 2, 0xFFFFFFF3);
  test_bit_reset_n(2, 3, 0xFFFFFFE3);
  test_bit_reset_n(2, 4, 0xFFFFFFC3);
  test_bit_reset_n(2, 5, 0xFFFFFF83);
  test_bit_reset_n(2, 6, 0xFFFFFF03);

  // Start from position 3 for n bits
  test_bit_reset_n(3, 2, 0xFFFFFFE7);
  test_bit_reset_n(3, 3, 0xFFFFFFC7);
  test_bit_reset_n(3, 4, 0xFFFFFF87);
  test_bit_reset_n(3, 5, 0xFFFFFF07);

  // Start from position 4 for n bits
  test_bit_reset_n(4, 2, 0xFFFFFFCF);
  test_bit_reset_n(4, 3, 0xFFFFFF8F);
  test_bit_reset_n(4, 4, 0xFFFFFF0F);

  // Start from position 5 for n bits
  test_bit_reset_n(5, 2, 0xFFFFFF9F);
  test_bit_reset_n(5, 3, 0xFFFFFF1F);

  // Start from position 6 for n bits
  test_bit_reset_n(6, 2, 0xFFFFFF3F);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_bit_reset);
  RUN_TEST(test_bit_reset_n_different_bit_mask);
  RUN_TEST(test_bit_reset_n_different_start_position);
  RUN_TEST(test_bit_reset_n_different_bit_mask_and_start_position);
  return UNITY_END();
}
