#ifndef ARMOUR_U_ENCODER_H
#define ARMOUR_U_ENCODER_H

#include <cstdint>

namespace enc {

/**
 * Template class for minimal, generic, unsigned type operations
 * @tparam UT underlying unsigned type
 */
template<typename UT>
class UEncoder {
 public:
  using u_type = UT;

  UEncoder(u_type value)
      : value_{value} {}

  constexpr inline u_type value_at(const uint8_t shift, const uint8_t len) const {
    return ((value_ & (((1 << len) - 1) << shift)) >> shift);
  }

  inline void zero_at(const uint8_t shift, const uint8_t len) {
    value_ ^= (value_ & (((1 << len) - 1) << shift));
  }

  constexpr operator u_type() const;

 protected:
  u_type value_;
  const uint8_t u_size_ = sizeof(UT);
};

} // namespace enc

#endif //ARMOUR_U_ENCODER_H
