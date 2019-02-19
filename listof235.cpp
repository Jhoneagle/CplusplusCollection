#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n;
set<long long> numbers;

int main() {
  long long n;
  long long r = 0;
  cin >> n;
  
  numbers.insert(2);
  numbers.insert(3);
  numbers.insert(5);
  
  auto c = numbers.begin();
  
  while (n > 0) {
    r = *c;
    
    numbers.insert(r * 2);
    numbers.insert(r * 3);
    numbers.insert(r * 5);
    
    n--;
    c++;
  }
  
  cout << r << "\n";
  return 0;
}