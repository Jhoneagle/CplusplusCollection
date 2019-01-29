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

  vector<string> words(n);
  vector<string> result;
  string s;

  for (long long i = 0; i < n; i++) {
    cin >> s;
    words[i] = s;
  }
  
  result.push_back(words[0]);
  
  for (long long i = 1; i < n; i++) {
    string temp = words[i];
    bool isEquilevant = false;
    
    for (auto r : result) {
      if (compare(temp, r)) {
        isEquilevant = true;
        break;
      }
    }
    
    if (isEquilevant == false) result.push_back(temp);
  }
  
  cout << result.size() << "\n";
  return 0;
}