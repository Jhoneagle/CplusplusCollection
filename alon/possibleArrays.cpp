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
  vector<number> values(n + 10);
  
  for (number i = 1; i <= n; i++) {
    cin >> values[i];
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
      number diff = last - before - 1;
      
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
      
      number times[(diff + 10)][(m + 10)] = {0};
      
      if (valueBefore == -1) {
        for (number a = 1; a <= m; a++) times[1][a] = 1;
      } else {
        for (number a = (valueBefore - 1); a <= (valueBefore + 1); a++) times[1][a] = 1;
	
	times[1][m + 1] = 0;
	times[1][0] = 0;
      }
      
      for (number a = 2; a <= diff; a++) {
	for (number b = 1; b <= m; b++) {
	  number sum = times[a - 1][b - 1];
	  sum = (sum + times[a - 1][b])  % 1000000007;
	  sum = (sum + times[a - 1][b + 1])  % 1000000007;
	  times[a][b] = sum;
        }
      }
	
      temp = 0;
      
      if (valueAfter == -1) {
        for (number a = 1; a <= m; a++) temp = (temp + times[diff][a])  % 1000000007;
      } else {
	number sum = times[diff][valueAfter - 1];
        sum = (sum + times[diff][valueAfter])  % 1000000007;
	sum = (sum + times[diff][valueAfter + 1])  % 1000000007;
	temp = sum; 
      }
      
      result = (result * temp) % 1000000007;
      
      if (last == -1) break;
      
      i = last;
      before = last;
    }
  }
  
  cout << result << endl;
  return 0;
}