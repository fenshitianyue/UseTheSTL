///////////////////////////////////////////////////////
// 标题：用优先级队列存储智能指针
// 说明：当生成优先级队列或堆时，需要一个顺序关系来确定元素
//      的顺序。当它保存的是原生指针或者智能指针时，总是需要
//      为它们提供一个比较函数；如果不提供，就会对它们所保存的
//      指针而不是指针所指向的对象进行比较。
///////////////////////////////////////////////////////

#include <queue>
#include <memory>
#include <string>
#include <vector>

using namespace std;

auto comp = [](const shared_ptr<string>& wp1, const shared_ptr<string>& wp2){
              return *wp1 < *wp2;
            };

int main() {
  //case 1 
  vector<shared_ptr<string>> init{make_shared<string>("one"), make_shared<string>("two"), 
                                  make_shared<string>("three"), make_shared<string>("four")};
  priority_queue<shared_ptr<string>, vector<shared_ptr<string>>, decltype(comp)> words_1(comp, init);
  //case 2
  priority_queue<shared_ptr<string>, vector<shared_ptr<string>>, decltype(comp)> words_2(comp);
  words_2.emplace(new string("five"));
  words_2.emplace(new string("six"));
  words_2.emplace(new string("seven"));
  words_2.emplace(new string("eight"));

  return 0;
}
