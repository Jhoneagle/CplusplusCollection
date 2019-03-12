#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

vector<number> planetsCosts;
number n, result, temp, sum, highest;

bool ok(number x) {
  number sum = 0;
  
  for (number i = 0; i < planetsCosts.size(); i++) {
    number value = planetsCosts[i];
    sum += value;
    
    if (sum < 0) return false;
    if (sum > x) sum = x;
  }
  
  return true;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  result = 0;
  sum = 0;
  highest = 0;
  bool isNegatives = false;
  
  for (number i = 0; i < n; i++) {
    cin >> temp;
    if (temp < 0) isNegatives = true;
    if (temp != 0) planetsCosts.push_back(temp);
  }
  
  if (planetsCosts.size() != 0 && isNegatives) {
    for (number i = 0; i < planetsCosts.size(); i++) {
      number value = planetsCosts[i];
      sum += value;
      if (sum < 0) {
        cout << -1 << endl;
        return 0;
      }
      
      if (value < 0) value *= -1;
      highest += value;
    }
    
    number x = 0;
    for (number b = highest; b >= 1; b /= 2) {
        while (!ok(x + b)) x += b;
    }
    
    result = x + 1;
  }
  
  cout << result << endl;
  return 0;
}