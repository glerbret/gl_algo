#include "../inc/luhn.h"
#include "../inc/mod97.h"

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <tuple>

void test_luhn()
{
  const std::vector<std::tuple<std::string, char>> test_number =
  {
    {"6703040366922800", 8},
    {"497288006106593",  5}
  };
  for(int i = 0; const auto& entry: test_number)
  {
    if(gl::luhn::calculate_key(std::get<0>(entry)) == std::get<1>(entry))
    {
      std::cout << "gl::luhn::calculate_key " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::luhn::calculate_key " << i + 1 << " KO\n";
    }
    ++i;
  }

  const std::vector<std::string> test_number_valid{"67030403669228008", "4972880061065935"};
  for(int i = 0; const auto& entry: test_number_valid)
  {
    if(gl::luhn::check_key(entry))
    {
      std::cout << "gl::luhn::check_key valide " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::luhn::check_key valide " << i + 1 << " KO\n";
    }
    ++i;
  }

  const std::vector<std::string> test_number_invalid{"67030403569228008", "4972880021065935"};
  for(int i = 0; const auto& entry: test_number_invalid)
  {
    if(!gl::luhn::check_key(entry))
    {
      std::cout << "gl::luhn::check_key invalide " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::luhn::check_key invalide " << i + 1 << " KO\n";
    }
    ++i;
  }
}

void test_rib()
{
  const std::vector<std::tuple<std::string, int>> test_number = {{"125480299800000001500", 86}};
  for(int i = 0; const auto& entry: test_number)
  {
    if(gl::mod97::calculate_rib_key(std::get<0>(entry)) == std::get<1>(entry))
    {
      std::cout << "gl::mod97::calculate_rib_key " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::mod97::calculate_rib_key " << i + 1 << " KO\n";
    }
    ++i;
  }

  const std::vector<std::string> test_number_valid{"12548029980000000150086"};
  for(int i = 0; const auto& entry: test_number_valid)
  {
    if(gl::mod97::check_rib_key(entry))
    {
      std::cout << "gl::mod97::check_rib_key valide " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::mod97::check_rib_key valide " << i + 1 << " KO\n";
    }
    ++i;
  }

  const std::vector<std::string> test_number_invalid{"12548029980000000150087"};
  for(int i = 0; const auto& entry: test_number_invalid)
  {
    if(!gl::mod97::check_rib_key(entry))
    {
      std::cout << "gl::mod97::check_rib_key invalide " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::mod97::check_rib_key invalide " << i + 1 << " KO\n";
    }
    ++i;
  }
}

void test_nir()
{
  const std::vector<std::tuple<std::string, int>> test_number = {{"1830278256123", 71}};
  for(int i = 0; const auto& entry: test_number)
  {
    if(gl::mod97::calculate_nir_key(std::get<0>(entry)) == std::get<1>(entry))
    {
      std::cout << "gl::mod97::calculate_nir_key " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::mod97::calculate_nir_key " << i + 1 << " KO\n";
    }
    ++i;
  }

  const std::vector<std::tuple<std::string, int>> test_number_valid = {{"1830278256123", 71}};
  for(int i = 0; const auto& entry: test_number_valid)
  {
    if(gl::mod97::check_nir_key(std::get<0>(entry), std::get<1>(entry)))
    {
      std::cout << "gl::mod97::check_nir_key valide " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::mod97::check_nir_key valide " << i + 1 << " KO\n";
    }
    ++i;
  }

  const std::vector<std::tuple<std::string, int>> test_number_invalid = {{"1830278256123", 63}};
  for(int i = 0; const auto& entry: test_number_invalid)
  {
    if(!gl::mod97::check_nir_key(std::get<0>(entry), std::get<1>(entry)))
    {
      std::cout << "gl::mod97::check_nir_key invalide " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::mod97::check_nir_key invalide " << i + 1 << " KO\n";
    }
    ++i;
  }
}

void test_rmlc()
{
  const std::vector<std::tuple<std::string, int>> test_number = {{"6679545042014506908052108899000",  90}};
  for(int i = 0; const auto& entry: test_number)
  {
    if(gl::mod97::calculate_rmlc_key(std::get<0>(entry)) == std::get<1>(entry))
    {
      std::cout << "gl::mod97::calculate_rmlc_key " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::mod97::calculate_rmlc_key " << i + 1 << " KO\n";
    }
    ++i;
  }

  const std::vector<std::string> test_number_valid{"667954504201450690805210889900090"};
  for(int i = 0; const auto& entry: test_number_valid)
  {
    if(gl::mod97::check_rmlc_key(entry))
    {
      std::cout << "gl::mod97::check_rmlc_key valide " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::mod97::check_rmlc_key valide " << i + 1 << " KO\n";
    }
    ++i;
  }

  const std::vector<std::string> test_number_invalid{"667954504201450690805210889900012"};
  for(int i = 0; const auto& entry: test_number_invalid)
  {
    if(!gl::mod97::check_rmlc_key(entry))
    {
      std::cout << "gl::mod97::check_rmlc_key invalide " << i + 1 << " OK\n";
    }
    else
    {
      std::cout << "gl::mod97::check_rmlc_key invalide " << i + 1 << " KO\n";
    }
    ++i;
  }
}

int main()
{
  test_luhn();
  test_rib();
  test_nir();
  test_rmlc();
}
