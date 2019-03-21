#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long number;
 
number n, result, temp;
 
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  result = 0;
  vector<number> values(n + 1);
  
  for (number i = 1; i <= n; i++) {
    cin >> temp;
    values[i] = temp;
  }
  
  
  
  cout << result << endl;
  return 0;
}