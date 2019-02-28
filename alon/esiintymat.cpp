#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long sublistSize, size, largest, currentValue;
vector<long long> values;
map<long long, long long> howMany;
priority_queue<pair<long long, long long>> mostFreq;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> size >> sublistSize;
  
  for (long long i = 0; i < size; i++) {
    cin >> currentValue;
    values.push_back(currentValue);
  }
  
  largest = values[0];
  howMany[values[0]]++;
  
  for (long long i = 1; i < sublistSize; i++) {
    currentValue = values[i];
    howMany[currentValue]++;
  }
  
  for (auto it = howMany.begin(); it != howMany.end(); it++) {
    mostFreq.push({it->second, (-1 * it->first)});
  }
  
  largest = -1 * mostFreq.top().second;
  cout << largest << " ";
  
  for (long long i = sublistSize; i < size; i++) {
    howMany[values[i - sublistSize]]--;
    currentValue = values[i];
    howMany[currentValue]++;
    
    auto top = mostFreq.top();
    if ((-1 * top.second) == currentValue) {
      mostFreq.pop();
      mostFreq.push({howMany[currentValue], top.second});
    } else {
      vector<pair<long long, long long>> temp;
      
      while ((-1 * top.second) != currentValue) {
        mostFreq.pop();
        
        if (howMany[(-1 * top.second)] != top.first) top.first = howMany[(-1 * top.second)];
        
        temp.push_back(top);
	
	if (mostFreq.empty()) break;
	
        top = mostFreq.top();
      }
      
      if (mostFreq.empty()) {
        mostFreq.push({howMany[currentValue], -1 * currentValue});
      } else {
        mostFreq.pop();
        mostFreq.push({howMany[currentValue], top.second});
      }
      
      for (auto e : temp) mostFreq.push(e);
    }
    
    largest = -1 * mostFreq.top().second;
    cout << largest << " ";
  }
  
  cout << "\n";
  return 0;
}