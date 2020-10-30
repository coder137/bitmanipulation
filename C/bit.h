#ifndef BIT_H_
#define BIT_H_

#include <stdint.h>

//
// 32 BIT APIS
//

/**
 * @brief Creates a UINT32 BITMASK of size n
 * @param n Numbers of bits used to create the BITMASK
 * @return UINT32
 */
#define BIT_MASK(n) BIT_MASK_HELPER(n, uint32_t)

/**
 * @brief Set a BIT on the variable at a given position
 * @param var The output variable that is modified
 * @param pos The BIT position to set data (0 indexed)
 * @return UINT32
 */
#define BIT_SET_1(var, pos) (var | (1 << pos))

/**
 * @brief Set N BITS on the variable starting from a given position
 * @param var The output variable that is modified
 * @param start_pos The starting position of the bit (0 indexed)
 * @param n The number of bits used
 * @return UINT32
 */
#define BIT_SET_N(var, start_pos, n) (var | (BIT_MASK(n) << start_pos))

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

//
// 64 BIT APIS
//

/**
 * @brief Creates a UINT64 BITMASK of size n
 * @param n Number of bits used to create the BITMASK
 * @return UINT64
 */
#define BIT_MASK64(n) BIT_MASK_HELPER(n, uint64_t)

//
// HELPER APIS
//

/**
 * @brief A generic BIT MASK API for different datatypes
 * @param pos: Shift by current position
 * @param type: Datatype used (uint32_t, uint64_t)
 * @return sizeof(type)
 */
#define BIT_MASK_HELPER(pos, type) (~((type)(~0) << pos))

#endif
