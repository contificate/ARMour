#include "arm_encoder.h"

namespace enc {

arm_cond ARMEncoder::cond() const {
  return static_cast<arm_cond>(value_at(28, 4));
}

bool ARMEncoder::operator&(const arm_cond cond) const {
  return (value_at(28, 4) == static_cast<uint8_t>(cond));
}

} // namespace enc