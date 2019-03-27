#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, m, result, temp;
#define N (1<<18)
number tree[2 * N];

void update(number k, number x) {
  k += N;
  tree[k] = x;
  
  for (k /= 2; k >= 1; k /= 2) {
    tree[k] = max(tree[2 * k], tree[(2 * k)+1]);
  }
}

number getFirst(number needed) {
  number i = 1;
  
  if (tree[i] >= needed) {
    
  } else {
    return -1;
  }
  
  return i - N;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  
  for (number i = 1; i <= n; i++) {
    cin >> temp;
    update(i, temp);
  }
  
  for (number i = 1; i <= m; i++) {
    cin >> temp;
    number r = getFirst(temp);
    
    if (r > 0) {
      number changed = tree[r + N] - temp;
      update(r, changed);
    }
    
    cout << r << endl;
  }
  
  return 0;
}