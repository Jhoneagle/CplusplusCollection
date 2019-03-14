#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long number;

vector<number> f(1000000);
number n, k, result;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  
  f[1] = 2;
  f[2] = 4;
  for (int i = 3; i <= n; i++) {
    number sum = f[i - 1] + f[i - 2];
    f[i] = sum % 10;
  }	
  
  result = f[n];
  cout << result << endl;
  return 0;
}