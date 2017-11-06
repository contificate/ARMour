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

} // namespace arm

#endif //ARMOUR_ARM_H
