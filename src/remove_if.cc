#include <iostream>
#include <string>
#include <algorithm>


int main() {
  std::string str = "f,ar f,r,om ey,e  far, from he,a,rt";
  auto devide = std::remove_if(str.begin(), str.end(), [](char c) { return c == ','; });
  str.erase(devide, str.end());
  std::cout << str << std::endl;
  return 0;
}
