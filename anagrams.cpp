#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) { 
  unordered_map<char, int> mapA;
  unordered_map<char, int> mapB;

  for (int i = 0; i < a.length(); i++) {
    mapA[a[i]]++; 
  }
  
  for (int i = 0; i < b.length(); i++) {
    mapB[b[i]]++; 
  }
  
  for (int i = 'A'; i < 'Z'; i++) {
    if (mapB[i] != mapA[i]) return false;
  }
  
  return true; 
} 

int main() {
  long long n;
  cin >> n;

  string s;
  cin >> s;

  vector<string> result;
  result.push_back(s);

  for (long long i = 1; i < n; i++) {
    cin >> s;
    bool isEquilevant = false;
    
    for (auto r : result) {
      if (compare(s, r)) {
        isEquilevant = true;
        break;
      }
    }
    
    if (isEquilevant == false) result.push_back(s);
  }
  
  cout << result.size() << "\n";
  return 0;
}