#include "arm_encoder.h"

namespace enc {

arm_cond ARMEncoder::cond() const {
  return static_cast<arm_cond>(value_at(28, 4));
}

ARMEncoder::operator u_type() const {
  return value_;
}

bool ARMEncoder::operator&(const arm_cond cond) const {
  return (value_at(28, 4) == static_cast<uint8_t>(cond));
}

bool ARMEncoder::operator&(const arm_mask instr_mask) const {
  const uint32_t kMaskValue = static_cast<uint32_t>(instr_mask);
  return ((value_ & kMaskValue) == kMaskValue);
}

} // namespace enc