///////////////////////////////////////////////////////
// 如果想要用容器保存元素，通常保存容器的指针更好：
//  1.在容器中保存指针需要复制指针而不是它所指向的对象。复制指针通常比复制对象快。
//  2.对存放指针的容器内容进行排序比对对象排序快，因为只需要移动指针，不需要移动对象。
//  3.在容器中保存指针可以得到多态性。存放元素基类指针的容器也可以保存其他派生类型的
//    指针。（当要处理有共同基类的任意对象序列时，这种功能会很有用）
//    
//  4.保存智能指针要比保存原生指针安全，因为在对象不再被使用时，自由存储区的对象会被
//    自动删除（RAII），这样就不会造成由于疏忽而导致的内存泄露。
///////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

void save_native_ptr(){
  //init set
  vector<string> string_set;
  string_set.emplace_back("world");
  string_set.emplace_back("begin");
  string_set.emplace_back("iterator");
  string_set.emplace_back("unordered_map");

  vector<string*> words;
  for(auto it = string_set.begin(); it != string_set.end(); ++it){
    words.push_back(new string(*it));
  }
  for(const auto& it : words) 
    cout << *it << " ";
  cout << endl;
  //删除vector中指定的元素
  for(auto iter = words.begin(); iter != words.end();){
    if("world" == **iter){
      delete *iter; //如果不先释放指针指向的对象，直接删除元素，就会内存泄漏
      words.erase(iter);
    }else{
      ++iter;
    }
  }
  cout << "---------------" << endl;
  for(const auto& it : words) 
    cout << *it << " ";
  cout << endl;
  //不再使用vector后，要记得释放vector中原生指针所指向的对象内存
  for(auto& it : words)
    delete it;
  words.clear();
}

void save_master_ptr(){
  //init set
  vector<string> string_set;
  string_set.emplace_back("world");
  string_set.emplace_back("begin");
  string_set.emplace_back("iterator");
  string_set.emplace_back("unordered_map");

  vector<shared_ptr<string>> words;
  for(auto it = string_set.begin(); it != string_set.end(); ++it){
    words.push_back(make_shared<string>(*it));
  }
  for(const auto& it : words) 
    cout << *it << " ";
  cout << endl;
  //删除vector中指定的元素
  for(auto iter = words.begin(); iter != words.end();){
    if("world" == **iter){
      words.erase(iter); //存储智能指针的容器删除指定元素时，不用手动释放指针指向的对象内存，直接erase即可
    }else{
      ++iter;
    }
  }
  cout << "---------------" << endl;
  for(const auto& it : words) 
    cout << *it << " ";
  cout << endl;
  //不再使用vector后，存储智能指针的vector不用手动释放元素指向的对象内存
  words.clear();
}

int main() {
  //save_native_ptr(); 
  save_master_ptr();
  return 0;
}
