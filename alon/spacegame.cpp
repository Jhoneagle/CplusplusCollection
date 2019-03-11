#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<long long> list;
long long n, result, temp;

long long binarySearch(long long needed) {
  
  
  
}



int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  result = 0;
  
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    list.push_back(temp);
  }
  
  long long smallestValue = 0
  long long sum = 0;
  
  for (long long i = 0; i < n; i++) {
    temp = list[i];
    sum += temp;

    if (temp < smallestValue) smallestValue = temp;
    if (sum < 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  
  if (smallestValue < 0) {
    temp = -1 * smallestValue;
    result = binarySearch(temp);
    
    if (result < temp) {
      temp -= result;
      result += binarySearch(temp);
    }
  }
  
  cout << result << endl;
  return 0;
}