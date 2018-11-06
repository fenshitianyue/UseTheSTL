#include <iostream>
#include <string>
#include <set>
#include <map>


int main(){
  //创建空map
  std::map<std::string, size_t> words;
  //创建过滤单词集
  std::set<std::string> filter = {"The", "But", "And", "Or", "An", "A",
                             "the", "but", "and", "or", "an", "a"};
  //统计单词
  std::string word;
  while(getline(std::cin, word)){
    if(filter.find(word) == filter.end()){ //如果不在过滤集中，则计数
      ++words[word];
    }
  }
  
  //显示结果
  for(const auto& w : words){
    std::cout<< w.first << " occurs: " << w.second
             << (w.second > 1 ? " times " : " time ")
             <<std::endl;
  }
   
  return 0;
}
