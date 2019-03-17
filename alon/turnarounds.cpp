#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, result;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<string> strings(n + 1);
  number matrix[n + 1][n + 1];
  
  for (number i = 1; i <= n; i++) {
    cin >> strings[i];
  }	  
  
  
  
  result = matrix[n][n];
  cout << result << endl;
  return 0;
}