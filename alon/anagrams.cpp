#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long n;
  cin >> n;
  string s;
  
  unordered_map<string, long long> result;
	
  for (long long i = 0; i < n; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    result[s]++;
  }
  
  cout << result.size() << "\n";
  return 0;
}