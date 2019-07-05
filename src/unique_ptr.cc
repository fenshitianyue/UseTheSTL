//编译指令
//g++ $^ -o $@ -std=c++1y -L ~/third_part/lib/lboost

#include <memory>
#include <vector>
#include <string>
#include <boost/make_unique.hpp> //C++14标准才正式纳入make_unique，在此之前make_unique存在于boost

using namespace std;


int main() {
  vector<unique_ptr<string>> words;
  words.push_back(boost::make_unique<string>("one"));
  words.push_back(boost::make_unique<string>("two"));
  
  auto elem = boost::make_unique<string>("three");
  //words.push_back(elem); 编译失败：对于unique_ptr,任何关于拷贝容器元素的操作都会失败
  auto elem2 = boost::make_unique<string>("four");
  //words.emplace_back(elem); 编译失败：对于unique_ptr,任何关于拷贝容器元素的操作都会失败


  return 0;
}
