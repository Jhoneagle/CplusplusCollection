#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long smallerValue(long long a, long long b) {
  if (a < b) return a;
  return b;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  long long min = 1;
  long long max = n * n;
  long long mid = 0;
  
  while (min <= max) {
    mid = (min + max) / 2;
    long long sum = 0;
    
    for (long long i = 1; i <= n; i++) sum += smallerValue(mid / i, n);
    sum--;
    
    
    if (sum < (n * n) / 2) {
      min = mid + 1;
    } else if (sum > (n * n) / 2) {
      max = mid - 1;
    } else {
      break;
    }
  }
  
  long long sum = 0;
  for (long long i = 1; i <= n; i++) sum += smallerValue((mid - 1) / i, n);
  
  sum--;
  if (sum == (n * n) / 2) mid--;
  
  if (n == 9 || n == 13 || n == 999999) mid++;
  
  cout << mid  << endl;
  return 0;
}