#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

vector<pair<number, number>> bookings;
number customers, result, from, to;

bool ok(number start, number end) {
  for (auto pair : taken) {
    if (pair.first <= start && pair.second >= start) return false;
    if (pair.first <= end && pair.second >= end) return false;
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
      taken.push_back(pair);
    }
  }
  
  cout << result << endl;
  return 0;
}