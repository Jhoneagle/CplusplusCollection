#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> l;
unordered_map<long long, long long> numbers;

int main() {
  long long size;
  long long result = 0;
  long long v;
  cin >> size >> n;
  
  for (long long i = 0; i < size; i++) {
    cin >> v;
    l.push_back(v);
  }
  
  for (long long i = 0; i < size; i++) {
    for (long long j = 0; j <= i; j++) {
      numbers[j] += l[i];
      
      if (numbers[j] == n) result++;
    }
  }
  
  cout << result << "\n";
  return 0;
}