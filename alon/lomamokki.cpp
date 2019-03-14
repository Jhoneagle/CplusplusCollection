#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long number;
 
vector<pair<number, number>> bookings;
set<pair<number, number>> taken;
number customers, result, from, to;

bool ok(number start, number end) {
  auto where = taken.lower_bound({start, -1});
  
  if (where != taken.end()) {
    auto value = *where;
    
    if (value.first == start) return false;
    if (value.first <= end) return false;
    
    if (where != taken.begin()) {
      where--;
      auto previousValue = *where;
      if (start <= previousValue.second) return false;
    }
  } else {
    if (where != taken.begin()) {
      where--;
      auto previousValue = *where;
      if (start <= previousValue.second) return false;
    }
  }
  
  return true;
}
 
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> customers;
  result = -1;
  
  for (number i = 0; i < customers; i++) {
    cin >> from >> to;
    bookings.push_back({from, to});
  }
  
  for (number i = 0; i < customers; i++) {
    auto pair = bookings[i];
    
    if (!ok(pair.first, pair.second)) {
      result = i + 1;
      break;
    } else {
      taken.insert({pair.first, pair.second});
    }
  }
  
  cout << result << endl;
  return 0;
}