#include <iostream>
#include <vector> 
using namespace std;

class Bool {
  public:
    vector<int> pos;
    vector<int> vec;
}

int main() {
  
  bool logged_in = false;
  
  // Write the code below:
  
  if (not logged_in) {
    std::cout << "Try again";
  }
  
}