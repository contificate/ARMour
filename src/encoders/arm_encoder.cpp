#include "arm_encoder.h"

namespace enc {

arm_cond ARMEncoder::cond() const {
  return static_cast<arm_cond>(value_at(28, 4));
}

} // namespace enc