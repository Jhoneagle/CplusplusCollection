#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

vector<int> create_z(string s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  
  for (int i=1; i < n; i++) {
    z[i] = max(0, min(z[i - l], r - i));
    
    while (((i + z[i]) < n) && (s[z[i]] == s[i+z[i]])) {
      z[i]++;
    }
    
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  
  return z;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int result = 0;
  string str, pattern;
  cin >> str >> pattern;
  
  str = pattern + '$' + str;
  vector<int> zTable = create_z(str);
  
  number s = pattern.size();
  for (auto v : zTable) {
    if (v == s) result++; 
  }
  
  cout << result << endl;
  return 0;
}