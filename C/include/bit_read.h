#ifndef INCLUDE_BIT_READ_H_
#define INCLUDE_BIT_READ_H_

/**
 * @brief Read a BIT var from the variable at a given position
 * @param var The input variable to read from
 * @param pos The position of the bit to read (0 indexed)
 * @return UINT8
 */
#define BIT_READ_1(var, pos) ((var >> pos) & 0x01)

/**
 * @brief Read N BIT vars from the variable starting from a given position
 * @param var The input variable to read from
 * @param start_pos The starting position of the bit to read (0 indexed)
 * @param n Number of bits to read
 * @return UINT32
 */
#define BIT_READ_N(var, start_pos, n) ((var >> start_pos) & BIT_MASK(n))

#endif
