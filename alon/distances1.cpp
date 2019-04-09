#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, result, temp;
vector<number> tree[500001];
number lengthFirst[500001];
number lengthSecond[500001];
number childComeFrom[500001];
number finalList[500001];

void dfs(number node, number prev) {
  lengthFirst[node] = 0;
  lengthSecond[node] = 0;
  childComeFrom[node] = node;
  
  for (auto next : tree[node]) {
    if (next == prev) continue;
    
    dfs(next, node);
    
    if (lengthFirst[node] <= (lengthFirst[next] + 1)) {
      lengthSecond[node] = lengthFirst[node];
      lengthFirst[node] = lengthFirst[next] + 1;
      childComeFrom[node] = next;
    } else if (lengthSecond[node] <= (lengthFirst[next] + 1)) {
      lengthSecond[node] = lengthFirst[next] + 1;
    } 
  }
}

void dfsPrint(number node, number prev) {
  number parentSide = 1;
  if (childComeFrom[prev] == node) {
    parentSide += lengthSecond[prev];
  } else {
    parentSide += lengthFirst[prev];
  }
  
  if (lengthFirst[node] > parentSide) {
    if (lengthSecond[node] < parentSide) {
      lengthSecond[node] = parentSide;
    }
    
    finalList[node] = lengthFirst[node];
  } else {
    finalList[node] = parentSide;
    
    lengthSecond[node] = lengthFirst[node];
    lengthFirst[node] = parentSide;
    childComeFrom[node] = prev;
  }
  
  for (auto next : tree[node]) {
    if (next == prev) continue;
    dfsPrint(next, node);
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
  
  for (auto next : tree[1]) dfsPrint(next, 1);
  
  cout << lengthFirst[1] << " ";
  for (number i = 2; i <= n; i++) cout << finalList[i] << " ";
  
  cout << endl;
  return 0;
}