#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<long long> positives;

long long binarySearch(long long needed) {
  long long newStorage = 0;
  
  index = positives.size();
  
  
  
  return newStorage;
}

int main() {
  long long n, result, temp;
  cin >> n;
  vector<long long> negatives;
  result = 0;
  
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    
    if (temp < 0) negatives.push_back(temp);
    
    if (temp > 0) {
      positives.push_back(temp);
    }
  }
  
  sort(positives.begin(), positives.end());
  sort(negatives.begin(), negatives.end());
  
  for (long long i = 0; i < negatives.size(); i++) {
    temp = negatives[i];
    temp = binarySearch(-1 * temp);
    
    if (temp < 0) {
      result = -1;
      break;
    } else {
      if (temp > result) result = temp;
    }
  }
  
  cout << result << endl;
  return 0;
}