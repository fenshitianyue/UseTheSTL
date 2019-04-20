#include <iostream>
#include <algorithm>
#include <vector>

void test_vector(){
  std::vector<int> ve{1, 2, 3, 4, 5, 6, 7}; 
  auto result = std::find(ve.begin(), ve.end(), 5);
  if(result == ve.end()){
    std::cout << "not found" << std::endl;
  }else{
    std::cout << "目标元素下标：" << std::distance(ve.begin(), result) << std::endl;
  }
}

void test_else(){
  int arr[] = {1, 2, 3, 4, 5};
  int* result = std::find(std::begin(arr), std::end(arr), 7);
  if(result == std::end(arr)){
    std::cout << "not found" << std::endl;
  }else{
    std::cout << "目标元素下标：" << std::distance(std::begin(arr), result) << std::endl;
  }
}

int main() {
  //test_else();
  test_vector(); 
  return 0;
}
