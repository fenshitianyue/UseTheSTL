#include <iostream>
#include <map>
#include <string>
using namespace std;


int main() {
  map<string, size_t> m{make_pair("ann", 25)}; 
  auto pr = make_pair("jack", 22);
  auto ret_pr = m.insert(pr);
  cout << ret_pr.first->first << " " << ret_pr.first->second << " " << boolalpha << ret_pr.second << endl;
  return 0;
}
