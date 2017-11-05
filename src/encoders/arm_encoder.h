#ifndef ARMOUR_ARM_ENCODER_H
#define ARMOUR_ARM_ENCODER_H

#include "arm.h"
#include "u_encoder.h"

namespace enc {

using arm::arm_cond;

/**
 * Minimal ARM instruction encoding wrapper (specialisation of enc::UEncoder<> for uint32_t)
 */
class ARMEncoder : public UEncoder<uint32_t> {
 public:
  using u_type = UEncoder::u_type;

  explicit ARMEncoder(u_type value)
      : UEncoder(value) {}

  arm_cond cond() const;

  u_type operator&(const arm_cond cond) {
    return (value_ & static_cast<u_type>(cond));
  }

};

} // namespace enc

#endif //ARMOUR_ARM_ENCODER_H
