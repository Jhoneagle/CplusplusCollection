#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, q;
number color[200001] = {0};
vector<number> adj[200001];
vector<number> result;

void dfs(number s) {
  if (color[s] == 1) {
    cout << "Error ";
    return;
  } else if (color[s] == 2) {
    return;
  } else {
    color[s] = 1;
  }
  
  for (auto u : adj[s]) dfs(u);
  
  color[s] = 2;
  result.push_back(s);
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  
  number a, b;
  for (number i = 0; i < q; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
  }
  
  for (number i = 1; i <= n; i++) dfs(i);
  for (number i = (n - 1); i >= 0; i--) cout << result[i] << " ";
  
  cout << endl;
  return 0;
}