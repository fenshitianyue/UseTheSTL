#include <iostream>

double aver(std::initializer_list<double> l){
  double sum = 0.0;
  double n = 0;
  for(auto it = l.begin(); it != l.end(); ++it){
    sum += *it;
    n++;
  }
  return sum / n;
}

int main() {
  double sum1 = aver({1.2, 9.9, 4,5}); 
  double sum2 = aver({100, 200}); 
  std::cout << "sum1 = " << sum1 << std::endl;
  std::cout << "sum2 = " << sum2 << std::endl;
  return 0;
}
