#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, result, temp;

void printTreeEdges(number prufer[]) { 
  unordered_map<number, number> nodeCount;
  set<number> leaves;

  number len = n - 2;

  for (number i = 0; i < len; i++) {
    number t = prufer[i];
    nodeCount[t]++;
  }

  for (number i = 1; i <= n; i++) {
    if (nodeCount.find(i) == nodeCount.end()) leaves.insert(i);
  }

  for (number i = 0; i < len; i++){
    number a = prufer[i];
    number b = *leaves.begin(); 
    
    cout << a << " " << b << "\n";
    
    leaves.erase (b);
    nodeCount[a]--;
    
    if (nodeCount[a] == 0) leaves.insert(a);
  }

  cout << *leaves.begin() << " " << *leaves.rbegin();
} 

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  number prufer[n - 2];
  for (number i = 0; i < (n - 2); i++) cin >> prufer[i];
  
  printTreeEdges(prufer);
  cout << endl;
  return 0;
}