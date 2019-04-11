#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n;
vector<number> tree[500001];
number childrens[500001];
number sumDistances[500001];

void dfs(number node, number prev) {
  number sum = 0;
  number amount = 1;
  
  for (auto next : tree[node]) {
    if (next == prev) continue;
    
    dfs(next, node);
    sum += childrens[next] + sumDistances[next];
    amount += childrens[next];
  }
  
  sumDistances[node] = sum;
  childrens[node] = amount;
}

void includeParent(number node, number parent) {
  sumDistances[node] = sumDistances[parent] - childrens[node] + (n - childrens[node]);
  
  for (auto next : tree[node]) {
    if (next == parent) continue;
    includeParent(next, node);
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
  
  dfs(1, 0);
  for (auto go : tree[1]) includeParent(go, 1);
  
  for (number i = 1; i <= n; i++) cout << sumDistances[i] << " ";
  cout << endl;
  return 0;
}