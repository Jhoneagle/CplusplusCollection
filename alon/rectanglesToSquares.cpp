#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number dp[501][501];
number a, b, result, temp;

number minimumSquare(number m, number n) { 
  number vertical_min = INT_MAX; 
  number horizontal_min = INT_MAX; 
  
  if (m == n) return 1; 
  
  if (dp[m][n]) return dp[m][n]; 
  
  for (number i = 1; i <= m / 2; i++) { 
    horizontal_min = min(minimumSquare(i, n) + minimumSquare(m - i, n), horizontal_min);  
  } 
      
  for (number j = 1; j <= n / 2; j++) { 
    vertical_min = min(minimumSquare(m, j) + minimumSquare(m, n - j), vertical_min); 
  } 
          
  dp[m][n] = min(vertical_min, horizontal_min);  
          
  return dp[m][n]; 
} 

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  
  result = minimumSquare(a, b) - 1;
  cout << result << endl;
  return 0;
}