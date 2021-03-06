#pragma once

#include <utility>
#include <cstring>

class String{
public:
  //无参构造函数
  String() : data_(new char[1]) {
    *data_ = '\0';
  }
  //有参构造函数
  String(const char* str) : data_(new char[strlen(str) + 1]){
    strcpy(data_, str);
  }
  //拷贝构造函数
  String(const String& s) : data_(new char[s.size() + 1]){
    strcpy(data_, s.c_str());
  }
  //重载赋值运算符 //pass-by-value 方式
  String& operator=(String s){
    swap(s); 
    return *this;
  }
  //String& operator=(String&& s){
  //  swap(s);
  //  return *this;
  //}
  //移动构造函数
  String(String&& s) : data_(s.data_){
    s.data_ = nullptr;
  }
  //析构函数
  ~String(){
    delete[] data_;
  }
  //长度接口
  size_t size() const {
    return strlen(data_);
  }
  //C字符串接口
  char* c_str() const {
    return data_;
  }
  //交换接口
  void swap(String& s){
    std::swap(data_, s.data_);
  }
  //operator== 接口
  //operator< 接口
  //operator[] 接口
private:
  char* data_;
};

//test case
//#include <iostream>
//#include "explain_string.hpp"
//using namespace std;
//
//int main() {
//  String s1("hello"); 
//  String s2;
//  s2 = String("world");
//  cout << s1.c_str() << " " << s2.c_str() << endl;
//  cout << "s1.size() : " << s1.size() << endl;
//  cout << "s2.size() : " << s2.size() << endl;
//  
//  return 0;
//}

