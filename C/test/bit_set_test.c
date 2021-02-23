#include "bit.h"
#include "unity.h"

// Static functions
static void tester_bit_set_1(uint8_t pos, uint32_t actual) {
  uint32_t value = BIT_SET_1(0, pos);
  TEST_ASSERT_EQUAL_UINT32(value, actual);
}

static void tester_bit_set_n(uint8_t start_pos, uint8_t n, uint32_t actual) {
  uint32_t value = BIT_SET_N(0, start_pos, n);
  TEST_ASSERT_EQUAL_UINT32(value, actual);
}

// static void tester_bit_set_inplace_n(uint8_t start_pos, uint8_t n, uint32_t
// actual) {
//   uint32_t value = 0;
//   BIT_SET_INPLACE_N(value, start_pos, n);
//   TEST_ASSERT_EQUAL_UINT32(value, actual);
// }

void setUp() {}
void tearDown() {}

// Set Bit 1
void test_bit_set_1(void) {
  tester_bit_set_1(0, 0x01);

  tester_bit_set_1(1, 0x02);

  tester_bit_set_1(2, 0x04);

  tester_bit_set_1(3, 0x08);

  tester_bit_set_1(4, 0x10);

  // Automated
  for (int i = 0; i < 32; i++) {
    tester_bit_set_1(i, (1 << i));
  }

  // Overflow will cause a -Wshift-count-overflow compile time error
  // NOTE, Only works on constants
  // BIT_SET_1(0, 32);
}

// Set Bit N

void test_bit_set_n_different_bit_mask(void) {
  // Check Manually
  tester_bit_set_n(0, 0, 0x00);
  tester_bit_set_n(0, 1, 0x01);
  tester_bit_set_n(0, 2, 0x03);
  tester_bit_set_n(0, 3, 0x07);
  tester_bit_set_n(0, 4, 0x0F);

  // Check automated
  for (int i = 0; i < 32; i++) {
    tester_bit_set_n(0, i, BIT_MASK(i));
  }
}

void test_bit_set_n_different_start_position(void) {
  // Check Manually
  tester_bit_set_n(0, 1, 0x01);
  tester_bit_set_n(1, 1, 0x02);
  tester_bit_set_n(2, 1, 0x04);
  tester_bit_set_n(3, 1, 0x08);

  // Check automated
  for (int i = 0; i < 32; i++) {
    tester_bit_set_n(i, 1, (1 << i));
  }
}

void test_bit_set_n_different_bit_mask_and_start_position(void) {
  // Start from position 1 for n bits
  tester_bit_set_n(1, 2, 0b0110);
  tester_bit_set_n(1, 3, 0b1110);
  tester_bit_set_n(1, 4, 0b00011110);
  tester_bit_set_n(1, 5, 0b00111110);
  tester_bit_set_n(1, 6, 0b01111110);
  tester_bit_set_n(1, 7, 0b11111110);

  // Start from position 2 for n bits
  tester_bit_set_n(2, 2, 0b1100);
  tester_bit_set_n(2, 3, 0b00011100);
  tester_bit_set_n(2, 4, 0b00111100);
  tester_bit_set_n(2, 5, 0b01111100);
  tester_bit_set_n(2, 6, 0b11111100);

  // Start from position 3 for n bits
  tester_bit_set_n(3, 2, 0b00011000);
  tester_bit_set_n(3, 3, 0b00111000);
  tester_bit_set_n(3, 4, 0b01111000);
  tester_bit_set_n(3, 5, 0b11111000);

  // Start from position 4 for n bits
  tester_bit_set_n(4, 2, 0b00110000);
  tester_bit_set_n(4, 3, 0b01110000);
  tester_bit_set_n(4, 4, 0b11110000);

  // Start from position 5 for n bits
  tester_bit_set_n(5, 2, 0b01100000);
  tester_bit_set_n(5, 3, 0b11100000);

  // Start from position 6 for n bits
  tester_bit_set_n(6, 2, 0b11000000);
}

// Set Inplace 1
void test_bit_inplace_1() {}

// Set inplace n
void test_bit_inplace_n() {}

int main() {
  UNITY_BEGIN();

  // Set 1
  RUN_TEST(test_bit_set_1);

  // Set n
  RUN_TEST(test_bit_set_n_different_bit_mask);
  RUN_TEST(test_bit_set_n_different_start_position);
  RUN_TEST(test_bit_set_n_different_bit_mask_and_start_position);

  // Inplace 1
  RUN_TEST(test_bit_inplace_1);

  // Inplace n
  RUN_TEST(test_bit_inplace_n);

  return UNITY_END();
}
