#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long sublistSize, size, largest, currentValue;
vector<long long> l;
map<long long, long long> howMany;
priority_queue<pair<long long, long long>> mostFreq;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> size >> sublistSize;
  
  for (long long i = 0; i < size; i++) {
    cin >> currentValue;
    l.push_back(currentValue);
  }
  
  largest = l[0];
  howMany[l[0]]++;
  
  for (long long i = 1; i < sublistSize; i++) {
    currentValue = l[i];
    howMany[currentValue]++;
  }
  
  for (auto it = howMany.begin(); it != howMany.end(); it++) {
    mostFreq.push({it->second, (-1 * it->first)});
  }
  
  largest = -1 * mostFreq.top().second;
  cout << largest << " ";
  
  for (long long i = sublistSize; i < size; i++) {
    howMany[l[i - sublistSize]]--;
    currentValue = l[i];
    howMany[currentValue]++;
    
    
    
    largest = -1 * mostFreq.top().second;
    cout << largest << " ";
  }
  
  cout << "\n";
  return 0;
}