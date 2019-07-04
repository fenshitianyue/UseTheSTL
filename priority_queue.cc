///////////////////////////////////////////////////////
// 标题：用优先级队列来存储智能指针
// 说明：当生成优先级队列/堆时，需要一个顺序关系来确定
//    元素之间的顺序。当它们保存的是原生指针/智能指针时，
//    总是需要为它们提供一个比较函数，如果不提供，就会对
//    它们所保留的指针而不是指针所指向的对象进行比较
///////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <memory>
#include <string>

auto comp = [](const std::shared_ptr<std::string>& wp1, const std::shared_ptr<std::string>& wp2){
              return *wp1 < *wp2;
            };
int main() {
  //case 1
  std::vector<std::shared_ptr<std::string>> init{std::make_shared<std::string>("one"), std::make_shared<std::string>("two"), 
                                                 std::make_shared<std::string>("three"), std::make_shared<std::string>("four")};
  std::priority_queue<std::shared_ptr<std::string>,  
                      std::vector<std::shared_ptr<std::string>>, 
                      decltype(comp)> words_1(comp, init);  
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  //case 2
  std::priority_queue<std::shared_ptr<std::string>, 
                      std::vector<std::shared_ptr<std::string>>, 
                      decltype(comp)> words_2{comp};
  words_1.emplace(new std::string("five"));
  words_1.emplace(new std::string("six"));
  words_1.emplace(new std::string("seven"));
  words_1.emplace(new std::string("eight"));

  return 0;
}
