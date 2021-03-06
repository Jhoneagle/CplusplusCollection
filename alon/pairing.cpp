#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, result, temp;
vector<number> tree[500001];
bool used[500001] = { false };

void pairUp(number node, number prev) {
  for (auto next : tree[node]) {
    if (next == prev) continue;
    
    pairUp(next, node);
  }
  
  for (auto next : tree[node]) {
    if (next == prev) continue;
    
    if (used[next] == false) {
      used[node] = true;
      used[next] = true;
      result++;
      break;
    }
  }
}

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
  
  pairUp(1, 0);
  
  cout << result << endl;
  return 0;
}