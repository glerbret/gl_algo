#include "../inc/mod97.h"

#include <string_view>

namespace
{
  int calculate_modulus_97(std::string_view number)
  {
    int mod = 0;
    for(const auto c: number)
    {
      mod = ((mod * 10) + (c - '0')) % 97;
    }

    return mod;
  }
}

namespace gl::mod97
{
  int calculate_rib_key(std::string_view number)
  {
    int mod = calculate_modulus_97(number);
    mod = (mod * 100) % 97;
    mod = 97 - mod;

    return mod;
  }

  bool check_rib_key(std::string_view number)
  {
    return calculate_modulus_97(number) == 0;
  }

  int calculate_nir_key(std::string_view number)
  {
    int mod = calculate_modulus_97(number);
    mod = 97 - mod;

    return mod;
  }

  bool check_nir_key(std::string_view number, int key)
  {
    const int mod = calculate_modulus_97(number);

    return mod + key == 97;
  }

  int calculate_rmlc_key(std::string_view number)
  {
    int mod = calculate_modulus_97(number);
    mod = (mod * 100) % 97;
    mod = 97 - mod;

    return mod;
  }

  bool check_rmlc_key(std::string_view number)
  {
    return calculate_modulus_97(number) == 0;
  }
}
