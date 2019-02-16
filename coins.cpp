#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>

using namespace std;

long long n;
vector<long long> v;

long checkReverse(long long t) {
  long long wanted = -1;
  long long sum = 0;
  
  for (int j = n; j >= 0; j--) {
    if ((sum + v[j]) == t) {
      wanted = sum + v[j];
      break;
    } else if ((sum + v[j]) < t) {
      sum += v[j];
    }
  }
  
  return wanted;
}

int main() {
  cin >> n;
  long long l = 0;
  long long r = 0;
  
  for (long long i = 0; i < n; i++) {
    cin >> l;
    v.push_back(l);
  }
  
  sort(v.begin(),v.end());
  long long cap = 1000000000;
  
  for (long long i = 1; i < cap; i++) {
    long long temp = checkReverse(i);
      
    if (temp == -1) {
      r = i;
      break;
    }
  }
  
  cout << r << '\n';
  return 0;
}