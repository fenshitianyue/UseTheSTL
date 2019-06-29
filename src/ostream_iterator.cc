#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
  vector<int> vec{1, 2, 3, 4, 5};
  for(const auto& it : vec){
    cout << it << ", ";
  }
  cout << endl;
  cout << "---------------" << endl;
  copy(vec.begin(), vec.end(), ostream_iterator<int>(std::cout, ", "));
  cout << endl; 
  return 0;
}
