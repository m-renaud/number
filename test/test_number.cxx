#include <iostream>
#include <utility>
#include <vector>

#include "../include/number.hxx"

int main()
{
  int i = 5;
  double d = 3.14;
  char c = 'A';

  std::vector<mrr::number> nums { std::ref(i), std::ref(d), std::ref(c) };

  for(auto& x : nums)
    ++x;

  std::cout << "i = " << i << std::endl;
  std::cout << "d = " << d << std::endl;
  std::cout << "c = " << c << std::endl;
}
