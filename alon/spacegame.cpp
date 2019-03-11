#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<long long> list;
long long n, result, temp;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  result = 0;
  
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    list.push_back(temp);
  }
  
  
  
  cout << result << endl;
  return 0;
}