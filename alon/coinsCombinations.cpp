#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long number;
 
number n, result, temp, k;
 
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  k = 0;
  result = 0;
  number values[n + 1];
  
  for (number i = 1; i <= n; i++) {
    cin >> temp;
    values[i] = temp;
    k += temp;
  }
  
  bool sums[k + 1] = {false};

  sums[0] = true;
  for (number i = 1; i <= n; i++) {
    for (number j = k; j >= 1; j--) {
        if ((j - values[i]) >= 0 && sums[j] == false) sums[j] = sums[j - values[i]];
    }
  }
  
  for (number i = 1; i <= k; i++) {
    if (sums[i] == true) result++;
  }
  
  cout << result << endl;
  
  for (number i = 1; i <= k; i++) {
    if (sums[i] == true) cout << i << " ";
  }
  
  cout << endl;
  return 0;
}