#ifndef INCLUDE_BIT_SET_H_
#define INCLUDE_BIT_SET_H_

/**
 * @brief Set N BITS on the variable/number starting from a given position
 * @param num That value
 * @param start_pos The starting position of the bit (0 indexed)
 * @param n The number of bits used
 * @return UINT32
 */
#define BIT_SET_N(num, start_pos, n) (num | (BIT_MASK(n) << start_pos))

/**
 * @brief Set a BIT on the variable/number at a given position
 * @param num The value
 * @param pos The BIT position to set data (0 indexed)
 * @return UINT32
 */
#define BIT_SET_1(num, pos) (BIT_SET_N(num, pos, 1))

/**
 * @brief Set N BITS on the variable starting from a given position
 * @param var The output variable that is modifiable
 * @param start_pos The starting position of the bit (0 indexed)
 * @param n The number of bits used
 */
#define BIT_SET_INPLACE_N(var, start_pos, n) \
  (var = (BIT_SET_N(var, start_pos, n)))

/**
 * @brief Set a BIT inplace on the variable at a given position
 * @param var The output variable that is modifiable
 * @param pos The BIT position to set data (0 indexed)
 */
#define BIT_SET_INPLACE_1(var, pos) (BIT_SET_INPLACE_N(var, pos, 1))

#endif
