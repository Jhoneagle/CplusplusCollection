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
  string given;
  cin >> given;
  
  vector<int> zTable = create_z(given);
  
  int s = given.size();
  for (number i = 0; i < s; i++) {
    if (zTable[i] == (s - i)) cout << i << " ";
  }
  
  cout << s << endl;
  return 0;
}