#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> ve{1, 2, 3, -5, -9, -8, 6};
  //std::transform(ve.begin(), ve.end(), ve.begin(), [](int i){ return i < 0 ? -i : i;  });
  std::transform(ve.begin(), ve.end(), ve.begin(), [](int i){
                    if(i < 0) return -i;
                    else return i;
                  }
                );
  std::for_each(ve.begin(), ve.end(), [](int i){ std::cout << i << " "; });
  std::cout << std::endl;
  return 0;
}
