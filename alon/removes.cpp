#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, result, temp;
#define N (1<<18)
number tree[2 * N] = {0};

void update(number k, number x) {
  k += N;
  tree[k] = x;
  
  for (k /= 2; k >= 1; k /= 2) {
    tree[k] = max(tree[2 * k], tree[(2 * k)+1]);
  }
}

number remove(number index) {
  
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  for (number i = 1; i <= n; i++) {
    cin >> temp;
    update(i, temp);
  }
  
  for (number i = 1; i <= n; i++) {
    cin >> temp;
    cout << remove(temp + N) << " ";
  }
  
  cout << endl;
  return 0;
}