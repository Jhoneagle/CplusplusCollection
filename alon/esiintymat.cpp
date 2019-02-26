#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n;
long long size;
vector<long long> l;
map<long long, long long> howMany;

int main() {
  priority_queue<pair<long long, long long>> mostFreq;
  cin.sync_with_stdio(0);
  cin.tie(0);
  long long v;
  cin >> size >> n;
  long long largest;
  
  for (long long i = 0; i < size; i++) {
    cin >> v;
    l.push_back(v);
  }
  
  largest = l[0];
  howMany[l[0]]++;
  
  for (long long i = 1; i < n; i++) {
    v = l[i];
    howMany[v]++;
  }
  
  for (auto it = howMany.begin(); it != howMany.end(); it++) {
    mostFreq.push({it->second, (-1 * it->first)});
  }
  
  largest = -1 * mostFreq.top().second;
  cout << largest << " ";
  
  for (long long i = n; i < size; i++) {
    howMany[l[i - n]]--;
    v = l[i];
    howMany[v]++;
    
    
    
    cout << largest << " ";
  }
  
  cout << "\n";
  return 0;
}