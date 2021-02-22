#ifndef INCLUDE_BIT_FLIP_H_
#define INCLUDE_BIT_FLIP_H_

/**
 * @brief Flip a BIT at a given position
 * @param var The output variable that is modified
 * @param pos The position of the bit to flip (0 indexed)
 * @return UINT32
 */
#define BIT_FLIP_1(var, pos) (var ^ (1 << pos))

/**
 * @brief Flip N BITS starting from a given position
 * @param var The output variable that is modified
 * @param start_pos The starting position of the bit to flip (0 indexed)
 * @param n Number of bits to flip
 * @return UINT32
 */
#define BIT_FLIP_N(var, start_pos, n) (var ^ (BIT_MASK(n) << start_pos))

#endif
