#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

const std::string&
transform(const std::string& s, const std::map<std::string, std::string>& m){
  auto map_it = m.find(s); //在构建的转换规则集合map中查找是否有单词s的转换规则
  if(map_it != m.cend()){ //如果找到了，则返回规则对应的转换后的单词
    return map_it->second;
  }else{
    return s; //否则返回原单词
  }
}

std::map<std::string, std::string> buildMap(std::ifstream& map_file){
  std::map<std::string, std::string> trans_map; //创建一个map保存转换规则
  std::string key; //要转换的单词
  std::string value; //转换后的内容
  while(map_file >> key && getline(map_file, value)){
    if(value.size() > 1){
      trans_map[key] = value.substr(1); //保存key的转换规则，跳过value中保存规则时开始读入的空格
    }else{
      throw std::runtime_error("no rule for" + key);
    }
  }
  return trans_map;
}


void word_transform(std::ifstream& map_file, std::ifstream& input){
  auto trans_map = buildMap(map_file); //保存转换规则
  std::string text; //保存每一行输入
  while(getline(input, text)){ 
    std::istringstream stream(text);//读取每一个单词
    std::string word;
    bool firstword_flag = true; //打印空格的标志
    while(stream >> word){
      if(firstword_flag) firstword_flag = false;
      else std::cout << " ";
      std::cout << transform(word, trans_map); //输出(arg1: 原始单词 arg2: 转换规则)
    }
    std::cout << std::endl;
  }
}

//test
int main() {
   
  return 0;
}
