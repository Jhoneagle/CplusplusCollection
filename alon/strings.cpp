#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>

using namespace std;

string n;
unordered_map<char, long long> v;
vector<char> r;

int main() {
  cin >> n;
  
  for (long long i = 0; i < n.size(); i++) {
    char l = n[i];
    v[l]++;
  }
  
  char p = 'a';
  
  for (long long i = 0; i < n.size(); i++) {
    char c = 'a';
    
    for (long long j = 'A'; j <= 'Z'; j++) {
      if (j != p && v[j] > ((n.size() - i) / 2) && v[j] > 0) {
        c = j;
	break;
      }
    }
    
    if (c == 'a') {
      for (long long j = 'A'; j <= 'Z'; j++) {
        if (j != p && v[j] > 0) {
          c = j;
	  break;
        }
      }
      
      if (c == 'a') {
        cout << "-1" << "\n";
        return 0;
      }
    }
    
    v[c]--;
    r.push_back(c);
    p = c;
  }
  
  for (auto s : r) cout << s;
  
  cout << "\n";
  return 0;
}