#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, result, temp;
#define N (1<<18)
number tree[2 * N] = {0};
vector<number> v;

void update(number k, number x) {
  k += N;
  tree[k] = x;
  
  for (k /= 2; k >= 1; k /= 2) {
    tree[k] = tree[2 * k] + tree[(2 * k) + 1];
  }
}

number remove(number index) {
  number i = 1;
  
  while (i < N) {
    if (tree[2 * i] >= index) {
      i *= 2;
    } else {
      index -= tree[2 * i];
      i = (2 * i) + 1;
    }
  }
  
  if (tree[i] == 1) {
    i -= N;
    update(i, 0);
    return v[i];
  } else {
    return -1;
  }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  for (number i = 1; i <= n; i++) {
    cin >> temp;
    update(i, 1);
    v.push_back(temp);
  }
  
  for (number i = 1; i <= n; i++) {
    cin >> temp;
    cout << remove(temp + N) << " ";
  }
  
  cout << endl;
  return 0;
}