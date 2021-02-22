#ifndef INCLUDE_BIT_RESET_H_
#define INCLUDE_BIT_RESET_H_

/**
 * @brief Clear a BIT from the variable at a given position
 * @param var This output variable that is modified
 * @param pos The BIT position to clear data (0 indexed)
 * @return UINT32
 */
#define BIT_RESET_1(var, pos) (var & ~(1 << pos))

/**
 * @brief Clear N BITS on the variable starting from a given position
 * @param var The output variable that is modified
 * @param start_pos The starting position of the bit (0 indexed)
 * @param n The number of bits used
 * @return UINT32
 */
#define BIT_RESET_N(var, start_pos, n) (var & ~(BIT_MASK(n) << start_pos))

#endif
