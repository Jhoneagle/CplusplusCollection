#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> v;
  
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      v.push_back(i * j);
    }
  }
  
  sort(v.begin(), v.end());
  
  long long middle = (n * n) / 2;
  cout << v[middle];
  
  cout << endl;
  return 0;
}