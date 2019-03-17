#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long number;

vector<number> f(1000001);
number n, k, result;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  
  f[1] = 2;
  f[2] = 4;
  f[3] = 8;
  f[4] = 16;
  f[5] = 32;
  f[6] = 64;
  f[7] = 128;
  f[8] = 256;
  f[9] = 512;
  f[10] = 1024;
  
  for (number i = (k + 1); i <= n; i++) {
    number sum = 0;
    
    for (number j = 1; j <= k; j++) sum += f[i - j];
    
    f[i] = sum % 1000000007;
  }	
  
  result = f[n];
  cout << result << endl;
  return 0;
}