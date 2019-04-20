#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Doc{
  int _weight; 
  std::string _doc;
};

int main() {
  std::vector<Doc> doc_set;
  for(int i = 1; i <= 10; ++i){
    doc_set.push_back({i, "something"});
  } 
  for(int i = 1; i <= 5; ++i){
    doc_set.push_back({i, "something"});
  } 
  std::sort(doc_set.begin(), doc_set.end(), 
            [](const Doc& d1, const Doc& d2){ return d1._weight < d2._weight; });
  auto end_unqiue = std::unique(doc_set.begin(), doc_set.end(), 
                                [](const Doc& d1, const Doc& d2) ->bool {
                                  if(d1._weight == d2._weight)
                                    return true;
                                  return false;
                                }
                               );
  doc_set.erase(end_unqiue, doc_set.end());
  std::for_each(doc_set.begin(), doc_set.end(), 
                [](const Doc& d){ std::cout << d._weight << " | " << d._doc << std::endl; });
  return 0;
}
