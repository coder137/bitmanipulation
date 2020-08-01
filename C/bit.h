#ifndef BIT_H_
#define BIT_H_

#include <stdint.h>

#define BIT_MASK_HELPER(pos, type) (~((type)(~0) << pos))

#define BIT_MASK(pos) BIT_MASK_HELPER(pos, uint32_t)
#define BIT_MASK64(pos) BIT_MASK_HELPER(pos, uint64_t)

#endif
