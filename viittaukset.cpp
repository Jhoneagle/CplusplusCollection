#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> v(n + 1);
  long long l = 0;

  for (long long i = 0; i < n; i++) {
    cin >> l;
    
    if (l >= v.size()) {
      long long temp = l + 1;
      v.resize(temp);
      n = l;
    }
    
    v[l] += 1;
  }
  
  l = 0;
  
  for (long long i = n; i > 0; i--) {
    l += v[i];
    
    //cout << "debug: " << i << " and " << v[i] << "\n";
    
    if (l >= i) {
      cout << i << "\n";
      return 0;
    }
  }
  
  cout << 0 << "\n";
  return 0;
}