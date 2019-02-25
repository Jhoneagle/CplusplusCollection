#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>

using namespace std;

long long n;
vector<long long> v;

int main() {
  cin >> n;
  long long l = 0;
  long long r = -1;
  
  for (long long i = 0; i < n; i++) {
    cin >> l;
    v.push_back(l);
  }
  
  sort(v.begin(),v.end());
  
  if (v[0] != 1) {
    r = 1;
  } else {
    long long sum = 1;
  
    for (auto x : v) {
      if (x > (sum + 1)) {
        break;
      } else {
        sum += x;
      }
    }
    
    r = sum;
  }
  
  cout << r << '\n';
  return 0;
}