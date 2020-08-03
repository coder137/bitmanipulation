#ifndef BIT_H_
#define BIT_H_

#include <stdint.h>

//
// 32 BIT APIS
//

/**
 * @brief Creates a UINT32 BITMASK of size n
 * @param n Numbers of bits used to create the BITMASK
 */
#define BIT_MASK(n) BIT_MASK_HELPER(n, uint32_t)

/**
 * @brief Set a BIT on the variable at a given position
 * @param value The output variable that is modified
 * @param pos The BIT position to set data (0 indexed)
 */
#define BIT_SET(value, pos) (value |= (1 << pos))

/**
 * @brief Set N BITS on the variable starting from a given position
 * @param value The output variable that is modified
 * @param start_pos The starting position of the bit (0 indexed)
 * @param n The number of bits used
 */
#define BIT_SET_N(value, start_pos, n) (value |= (BIT_MASK(n) << start_pos))

/**
 * @brief Clear a BIT on the variable at a given position
 * @param value This output variable that is modified
 * @param pos The BIT position to clear data (0 indexed)
 */
#define BIT_RESET(value, pos) (value &= ~(1 << pos))

/**
 * @brief Clear N BITS on the variable starting from a given position
 * @param value The output variable that is modified
 * @param start_pos The starting position of the bit (0 indexed)
 * @param n The number of bits used
 */
#define BIT_RESET_N(value, start_pos, n) (value &= ~(BIT_MASK(n) << start_pos))

//
// 64 BIT APIS
//

/**
 * @brief Creates a UINT64 BITMASK of size n
 * @param n Number of bits used to create the BITMASK
 */
#define BIT_MASK64(n) BIT_MASK_HELPER(n, uint64_t)

//
// HELPER APIS
//

/**
 * @brief A generic BIT MASK API for different datatypes
 * @param pos: Shift by current position
 * @param type: Datatype used (uint32_t, uint64_t)
 * @return
 */
#define BIT_MASK_HELPER(pos, type) (~((type)(~0) << pos))

#endif
