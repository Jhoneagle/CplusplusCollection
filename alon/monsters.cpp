#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

vector<string> strings(2501);
number n, result;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  for (number i = 1; i <= n; i++) {
    cin >> strings[i];
  }
  
  number matrix[n + 1][n + 1] = {0};
  
  for (number y = 1; y <= n; y++) {
    string value = strings[y];
    
    for (number x = 1; x <= n; x++) {
      if (value[x - 1] == '*') matrix[y][x]++;
      
      if ((y - 1) == 0) {
        matrix[y][x] += matrix[y][x - 1];
      } else if ((x - 1) == 0) {
        matrix[y][x] += matrix[y - 1][x];
      } else {
        matrix[y][x] += min(matrix[y][x - 1], matrix[y - 1][x]);
      }
    }
  }
  
  result = matrix[n][n];
  cout << result << endl;
  return 0;
}