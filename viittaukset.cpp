#include <iostream>
#include <bits/stdc++.h> 
#include <algorithm>

using namespace std;

int main() {
  long long n;
  cin >> n;
  map<long long, long long> v;
  long long l = 0;
  long long previous = -1;

  for (long long i = 0; i < n; i++) {
    cin >> l;
    v[l]++;
  }
  
  if (v.size() > 1) {
    l = 0;
  } else {
    if (n < v.begin()->first) {
      cout << n << "\n";
      return 0;
    } else {
      cout << v.begin()->first << "\n";
      return 0;
    }
  }
  
  for (auto i = v.rbegin(); i != v.rend(); i++) { 
      l += i->second;

      if (l == i->first || (i == v.rbegin() && l > i->first) || ((i->first - previous) == -1 && l > i->first)) {
        cout << i->first << "\n";
        return 0;
      } else if (l > i->first) {
        long long result = l - i->second;
	cout << result << "\n";
        return 0;
      } else {
        previous = i->first;
      }
  }
  
  cout << 0 << "\n";
  return 0;
}