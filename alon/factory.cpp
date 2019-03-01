#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long products, machines, currentTime, temp, made;
priority_queue<pair<long long, long long>> machinesWorking;
map<long long, long long> nSameMachines;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> machines >> products;
  currentTime = 0;
  
  if (machines == 1) {
    cin >> temp;
    cout << (temp * products) << "\n";
    return 0;
  }
  
  if (products == 1) {
    currentTime = 2147483647; // max value
    
    for (long long i = 0; i < machines; i++) {
      cin >> temp;
      if (temp < currentTime) currentTime = temp;
    }
    
    cout << currentTime << "\n";
    return 0;
  }
  
  for (long long i = 0; i < machines; i++) {
    cin >> temp;
    if (nSameMachines.find(temp) == nSameMachines.end()) machinesWorking.push({-temp, -temp});
    nSameMachines[temp]++;
  }
  
  while (made < products) {
    auto top = machinesWorking.top();
    machinesWorking.pop();
    
    made += nSameMachines[(-1 * top.second)];
    
    currentTime = top.first;
    long long nextReady = currentTime + top.second;
    machinesWorking.push({nextReady, top.second});
  }
  
  cout << (-1 * currentTime) << "\n";
  return 0;
}