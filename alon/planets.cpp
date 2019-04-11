#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, q, result;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  number jump[n + 1];
  
  for (number i = 1; i <= n; i++) cin >> jump[i];
  
  number a, b;
  for (number i = 1; i <= q; i++) {
    cin >> a >> b;
    result = a;
    
    for (number i = 1; i <= b; i++) result = jump[result];
    cout << result << "\n";
  }
  
  cout << endl;
  return 0;
}