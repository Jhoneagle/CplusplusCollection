#include <iostream>
#include <bits/stdc++.h> 
#include <algorithm>

using namespace std;

int main() {
  long long n;
  cin >> n;
  map<long long, long long> v;
  long long l = 0;

  for (long long i = 0; i < n; i++) {
    cin >> l;
    v[l]++;
  }
  
  
  
  return 0;
}