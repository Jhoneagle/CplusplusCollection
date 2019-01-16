#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

int main() {
  long tests;
  cin >> tests;
  vector <long long> firstNumbers;
  vector <long long> secondNumbers;
  long long a;
  long long b;
	
  for(long long i = 0; i < tests; i++) {
    cin >> a >> b;
    firstNumbers.push_back(a);
    secondNumbers.push_back(b);
  }
  
  for(long long i = 0; i < tests; i++) {
    a = firstNumbers[i];
    b = secondNumbers[i];
    
    if ((a == 0 && b != 0) || ( a!= 0 && b == 0)) {
      cout << "NO", cout << "\n";
    } else if ((a + b) % 3 == 0) {
      long long value = (a + b) / 3;
      if (value > a || value > b) {
        cout << "NO", cout << "\n";
      } else {
        cout << "YES", cout << "\n";
      }
    } else {
      cout << "NO", cout << "\n";
    }
  }
  
  return 0;
}
