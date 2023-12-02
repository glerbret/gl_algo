#include "../inc/luhn.h"

#include <string_view>

namespace
{
int calculate_luhn_sum(std::string_view number, int to_double)
{
  int sum = 0;

  for(auto it = std::crbegin(number); it != std::crend(number); ++it)
  {
    int value = (*it - '0') * to_double;
    if(value >= 10)
    {
      value = (value % 10) + 1;
    }

    sum += value;
    to_double = (to_double == 2 ? 1 : 2);
  }

  return sum;
}
}

namespace gl::luhn
{
  int calculate_key(std::string_view number)
  {
    int luhn = 10 - (calculate_luhn_sum(number, 2) % 10);
    if(luhn == 10)
    {
      luhn = 0;
    }

    return luhn;
  }

  bool check_key(std::string_view number)
  {
    return (calculate_luhn_sum(number, 1) % 10) == 0;
  }
}
