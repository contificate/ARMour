#ifndef ARMOUR_ARM_H
#define ARMOUR_ARM_H

#include <cstdint>

namespace arm {

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

} // namespace arm

#endif //ARMOUR_ARM_H
