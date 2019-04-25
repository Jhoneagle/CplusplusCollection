#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, q, result, temp;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  number jump[n + 1][33];
  
  for (number i = 1; i <= n; i++) {
    cin >> temp;
    jump[i][0] = temp;
  }
  
  for (number y = 1; y < 33; y++) {
    for (number i = 1; i <= n; i++) {
      number middle = jump[i][y - 1];
      jump[i][y] = jump[middle][y - 1];
    }
  }
  
  number a, b;
  for (number j = 1; j <= q; j++) {
    cin >> a >> b;
    
    if (b == 0) {
      cout << a << "\n";
      continue;
    }
    
    number i = 1, to = 0;
    while (i <= b) {
      i *= 2;
      to++;
    }
    
    i /= 2;
    to--;
    
    result = a;
    while (b > 0) {
      b -= i;
      result = jump[result][to];
      
      while (b < i) {
         i /= 2;
         to--;
      }
    }
    
    cout << result << "\n";
  }
  
  cout << endl;
  return 0;
}