#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long n;
  cin >> n;
  unordered_map<long long, long long> v;
  long long l = 0;

  for (long long i = 0; i < n; i++) {
    cin >> l;
    if (v.find(l) != v.end()) {
      v[l]++;
    } else {
      v[l] = 1;
    }
  }
  
  l = 0;
  
  for (long long i = n; i > 0; i--) {
    if (v.find(i) != v.end()) {
      l += v[i];
    } else {
      l = 0;
    }
    
    //cout << "debug: " << i << " and " << v[i] << "\n";
    
    if (l >= i) {
      cout << i << "\n";
      return 0;
    }
  }
  
  cout << 0 << "\n";
  return 0;
}