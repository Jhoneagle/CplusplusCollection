#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long sublistSize, size, largest, currentValue, temp;
vector<long long> values;
map<long long, long long> howMany;
set<pair<long long, long long>> mostFreq;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> size >> sublistSize;
  
  for (long long i = 0; i < size; i++) {
    cin >> temp;
    values.push_back(temp);
  }
  
  largest = values[0];
  howMany[values[0]]++;
  
  for (long long i = 1; i < sublistSize; i++) {
    currentValue = values[i];
    howMany[currentValue]++;
  }
  
  for (auto it = howMany.begin(); it != howMany.end(); it++) {
    mostFreq.insert({it->second, (-1 * it->first)});
  }
  
  auto pointer = mostFreq.rbegin();
  auto pair = *pointer;
  largest = -1 * pair.second;
  cout << largest << " ";
  
  for (long long i = sublistSize; i < size; i++) {
    temp = values[i - sublistSize];
    currentValue = values[i];
    
    if (currentValue != temp) {
      auto sub = mostFreq.find({howMany[temp], (-1 * temp)});
      if (sub != mostFreq.end()) mostFreq.erase(sub);
      mostFreq.insert({howMany[temp] - 1, (-1 * temp)});
      
      auto add = mostFreq.find({howMany[currentValue], (-1 * currentValue)});
      if (add != mostFreq.end()) mostFreq.erase(add);
      mostFreq.insert({howMany[currentValue] + 1, (-1 * currentValue)});
    }
    
    howMany[temp]--;
    howMany[currentValue]++;
    
    pointer = mostFreq.rbegin();
    pair = *pointer;
    largest = -1 * pair.second;
    cout << largest << " ";
  }
  
  cout << "\n";
  return 0;
}