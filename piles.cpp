#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

int main() {
  long tests;
  cin >> tests;
  string pair;
  
  for(long long i = 0; i < tests; i++) {
    cin >> pair;
  }
  
  for(long long i = 0; i < tests; i++) {
    
    
    if(1 % 3 == 0) {
      cout << "YES", cout << "\n";
    } else {
      cout << "NO", cout << "\n";
    }
  }
  
  return 0;
}
