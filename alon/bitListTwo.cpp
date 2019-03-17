#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long number;
 
vector<number> f(1000001);
number n, k, result;
 
number howManyAtleast(number limit, number length) {
  if (length == 0) return 0;
  
  number two = 2;
  for (number i = 1; i <= length; i++) {
    f[i] = two % 1000000007;
    two *= 2;
  }
  
  for (number i = (length + 1); i <= limit; i++) {
    number sum = 0;
    for (number j = 1; j <= length; j++) sum += f[i - j];
    
    f[i] = sum % 1000000007;
  }
  
  return f[n];
}
 
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  
  number sum = 2;
  for (number i = 1; i < n; i++) sum = (sum * 2) % 1000000007;
  
  result = sum - howManyAtleast(n, k - 1);
  if (result < 0) result += 1000000007;
  
  cout << result << endl;
  return 0;
}