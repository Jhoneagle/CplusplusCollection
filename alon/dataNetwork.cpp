#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long num;

struct MaxFlow {
  vector<vector<int>> adj;
  vector<vector<num>> cap;
  vector<vector<bool>> real;
  vector<vector<int>> link;
  vector<bool> seen;

  MaxFlow(int n) : adj(n + 1), cap(n + 1), real(n + 1), link(n + 1), seen(n + 1) {}

  void addEdge(int a, int b, num c) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    cap[a].push_back(c);
    cap[b].push_back(0);
    real[a].push_back(1);
    real[b].push_back(0);
    link[a].push_back(adj[b].size() - 1);
    link[b].push_back(adj[a].size() - 1);
  }

  int dest;
  bool ok;

  void dfs(int x, int r) {
    if (x == dest) ok = true;
    if (ok || seen[x]) return;
    
    seen[x] = 1;
    
    for (int i = 0; i < adj[x].size(); i++) {
      int y = adj[x][i];
      int j = link[x][i];
      
      if (cap[x][i] >= r) {
        cap[x][i] -= r;
        cap[y][j] += r;
	
        dfs(adj[x][i], r);
	
        if (ok) return;
	
        cap[x][i] += r;
        cap[y][j] -= r;
      }
    }
  }

  num maxFlow(int a, int b) {
    num flow = 0;
    dest = b;
    
    for (int z = 1e9; z >= 1; z /= 2) {
      while (true) {
        ok = 0;
	
        for (int i = 0; i < seen.size(); i++) seen[i] = 0;
	
	dfs(a, z);
	
	if (!ok) break;
	
	flow += z;
      }
    }
	
    return flow;
  }
};

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  MaxFlow f(n);
  
  int a, b, c;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    f.addEdge(a, b, c);
  }
  
  cout << f.maxFlow(1, n) << "\n";
}