#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long number;
 
number n, k, result, temp;
 
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  vector<number> values(n + 1);
  
  for (number i = 1; i <= n; i++) {
    cin >> temp;
    values[i] = temp;
    k += temp;
  }
  
  if ((k % 2) == 1) {
    cout << 0 << endl;
    return 0;
  }
  
  number sums[k + 1] = {0};

  sums[0] = 1;
  for (number i = 1; i <= n; i++) {
    for (number j = k; j >= 1; j--) {
        if ((j - values[i]) >= 0) sums[j] = (sums[j] + sums[j - values[i]]) % 1000000007;
    }
  }
  
  result = sums[k / 2];
  cout << result << endl;
  return 0;
}