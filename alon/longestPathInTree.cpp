#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, result, temp;
vector<number> tree[500001];
number length[500001];

void dfs(number node, number prev) {
  length[node] = 0;
  
  for (auto next : tree[node]) {
    if (next == prev) continue;
    
    dfs(next, node);
    length[node] = max(length[node], length[next] + 1);
  }
}

number deepest(number node, number prev, number currentDepth, number wantedDepth) {
  if (currentDepth == wantedDepth) return node;
  
  for (auto next : tree[node]) {
    if (next == prev) continue;
    
    number isIt = deepest(next, node, currentDepth + 1, wantedDepth);
    if (isIt != -1) return isIt;
  }
  
  return -1;
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
  
  dfs(1, 0);
  temp = deepest(1, 0, 0, length[1]);
  dfs(temp, 0);
  result = length[temp];
  cout << result << endl;
  return 0;
}