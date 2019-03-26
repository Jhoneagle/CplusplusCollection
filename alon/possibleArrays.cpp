#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;
 
number n, m, result, temp;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  
  result = 1;
  vector<number> values(n + 1);
  
  for (number i = 1; i <= n; i++) {
    cin >> temp;
    values[i] = temp;
  }
  
  number before = 0;
  number last = 0;
  for (number i = 1; i <= n; i++) {
    if (values[i] != 0) {
      before = i;
    } else {
      last = i;
      while(last <= n && values[last] == 0) last++;
      
      number valueBefore;
      number valueAfter;
      
      if (before > 0) {
        valueBefore = values[before];
      } else {
        valueBefore = -1;
      }
      
      if (last <= n) {
        valueAfter = values[last];
      } else {
        valueAfter = -1;
      }
      
      
      
      i = last;
    }
    
    if (values[i] == 0) {
      if (i != 1 && (values[i - 1] == 1 || values[i - 1] == m)) {
        result = (result * 2) % 1000000007;
      } else if (i != n && (values[i + 1] == 1 || values[i + 1] == m)) {
        result = (result * 2) % 1000000007;
      } else {
        result = (result * 3) % 1000000007;
      }
    }
  }
  
  cout << result << endl;
  return 0;
}