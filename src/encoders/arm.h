#ifndef ARMOUR_ARM_H
#define ARMOUR_ARM_H

#include <cstdint>
#include <string>

namespace arm {

/**
 * The ARM instruction conditional execution modifier
 * Occupies the most significant 4 bits of the instruction.
 * By default, the value is AL (always).
 */
enum class arm_cond : uint8_t {
  EQ,
  NE,
  CS,
  CC,
  MI,
  PL,
  VS,
  VC,
  HI,
  LS,
  GE,
  LT,
  GT,
  LE,
  AL
};

/**
 * Get string representation of a ARM conditional execution modifier
 * @param cond arm condition field
 * @return string representation of the condition
 */
std::string arm_cond_to_str(const arm_cond cond);

/**
 * ARM instruciton group masks (only accomodationg relevant ones for ROP and filtering)
 */
enum class arm_mask : uint32_t {
  /**
   * Branch and exchange
   *
   */
      BX = 0b00000001001011111111111100010000,
  /**
   * Single load/store
   * The 20th bit of this being set (1) indicates a load.
   */
      LDR = 0b0000010000000000000000000000000,
  /**
   * Load store block (multiple, e.g. ldmfd sp!, {r0-r3, pc})
   * The 20th bit of this being set (1) indicates a load.
   */
      LDM = 0b00001000000000000000000000000000
};

} // namespace arm

#endif //ARMOUR_ARM_H
