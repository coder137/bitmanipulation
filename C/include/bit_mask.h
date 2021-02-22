#ifndef INCLUDE_BIT_MASK_H_
#define INCLUDE_BIT_MASK_H_

/**
 * @brief A generic BIT MASK API for different datatypes
 * @param pos: Shift by current position
 * @param type: Datatype used (uint32_t, uint64_t)
 * @return sizeof(type)
 */
#define BIT_MASK_HELPER(pos, type) (~((type)(~0) << pos))

/**
 * @brief Creates a UINT32 BITMASK of size n
 * @param n Numbers of bits used to create the BITMASK
 * @return UINT32
 */
#define BIT_MASK(n) BIT_MASK_HELPER(n, uint32_t)

/**
 * @brief Creates a UINT64 BITMASK of size n
 * @param n Number of bits used to create the BITMASK
 * @return UINT64
 */
#define BIT_MASK64(n) BIT_MASK_HELPER(n, uint64_t)

#endif
