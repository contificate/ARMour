#ifndef ARMOUR_ARM_ENCODER_H
#define ARMOUR_ARM_ENCODER_H

#include "arm.h"
#include "u_encoder.h"

namespace enc {

using namespace arm;

/**
 * Minimal ARM instruction encoding wrapper (specialisation of enc::UEncoder<> for uint32_t)
 */
class ARMEncoder : public UEncoder<uint32_t> {
 public:
  using u_type = UEncoder::u_type;

  explicit ARMEncoder(u_type value)
      : UEncoder(value) {}

  arm_cond cond() const;

  operator u_type() const;

  bool operator&(const arm_cond cond) const;
  bool operator&(const arm_mask instr_mask) const;
};

} // namespace enc

#endif //ARMOUR_ARM_ENCODER_H
