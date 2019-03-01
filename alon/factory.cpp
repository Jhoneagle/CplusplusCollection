#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k, mnd = INT_MAX, mxd = INT_MIN;
  cin >> n >> k;
  vector<long long> v(n);
  
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] < mnd) mnd = v[i];
  }

  mxd = mnd * k;
  mnd = k / n + (k % n > 0 ? 1 : 0);
  
  while (mnd < mxd) {
    long long mid = (mnd + mxd) >> 1, item = 0;
    
    for (long long i = 0; i < n; i++) item += (mid / v[i]);
    
    if (item >= k) {
      mxd = mid;
    } else {
      mnd = mid + 1;
    }
  }
  
  cout << mnd << endl;
  return 0;
}