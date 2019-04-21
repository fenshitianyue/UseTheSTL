#include <iostream>
#include <vector>
#include <algorithm>


int main() {
  std::vector<int> ve{1, 2, 3, 4, 5}; 
  std::reverse(ve.begin(), ve.end());
  std::for_each(ve.begin(), ve.end(), [](const int& n) { std::cout << n << " "; });
  std::cout << std::endl;
  return 0;
}
