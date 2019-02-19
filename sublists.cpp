#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> numbers;

int main() {
  long long size;
  long long r;
  cin >> size >> n;
  
  for (long long i = 0; i < size; i++) {
    cin >> r;
    numbers.push_back(r);
  }
  
  r = 0;
  long long sumFirst;
  
  for (long long i = 0; i < numbers.size(); i++) {
    sumFirst = numbers[i];
    
    if (n == sumFirst) {
      r++;
    }
    
    for (long long j = (i + 1); j < numbers.size(); j++) {
      sumFirst += numbers[j];
      if (n == sumFirst) {
        r++;
      }
    }
  }
  
  cout << r << "\n";
  return 0;
}