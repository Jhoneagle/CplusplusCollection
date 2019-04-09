#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, result, temp;
vector<number> tree[500001];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  number a, b;
  for (number i = 1; i < n; i++) {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  
  
  cout << endl;
  return 0;
}