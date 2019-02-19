#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long roomsAmount;
  long long customersAmount;
  
  cin >> roomsAmount >> customersAmount;
  
  long long roomSize;
  long long customerSize;
  multiset<long long> rooms;
  vector<long long> customers;
  
  for (long long i = 0; i < roomsAmount; i++) {
    cin >> roomSize;
    rooms.insert(roomSize);
  }
  
  for (long long i = 0; i < customersAmount; i++) {
    cin >> customerSize;
    customers.push_back(customerSize);
  }
  
  for (auto p : customers) {
    auto size = rooms.lower_bound(p);
    
    if (size == rooms.end()) {
      cout << "-1" << " ";
    } else {
      cout << *size << " ";
      rooms.erase(size);
    }
  }
  
  cout << "\n";
  return 0;
}