#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number tree[1000000];
number n, q, result, temp;

number getMax(number a, number b) {
  a += (n - 1); 
  b += (n - 1);
  number x = tree[a];
  
  while (a <= b) {
    if (a % 2 == 1) x = max(x, tree[a++]);
    if (b % 2 == 0) x = max(x, tree[b--]);
    
    a /= 2; 
    b /= 2;
  }
  
  return x;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  
  number a, b;
  vector<pair<number, number>> queries;
  
  if ((n & (n - 1)) != 0) {
    temp = n;
    while ((n & (n - 1)) != 0) n++;
    
    for (number i = n; i < (n + temp); i++) cin >> tree[i];
    
    for (number i = 0; i < q; i++) {
      cin >> a >> b;
      queries.push_back({a, b});
    }
    
    for (number i = (n + temp); i < (2 * n); i++) tree[i] = -1;
  } else {
    for (number i = n; i < (2 * n); i++) cin >> tree[i];
    
    for (number i = 0; i < q; i++) {
      cin >> a >> b;
      queries.push_back({a, b});
    }
  }
  
  for (number i = (n - 1); i > 0; i--) {
    tree[i] = max(tree[2 * i], tree[(2 * i) + 1]);
  }
  
  for (auto query : queries) cout << getMax(query.first, query.second) << endl;
  
  return 0;
}

/*
more elegant solution (example answer)

#define N (1<<18)
int tree[2*N];

void update(int k, int x) {
    k += N;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = max(tree[2*k],tree[2*k+1]);
    }
}

int getMax(int a, int b) {
    a += N; b += N;
    int r = tree[a];
    while (a <= b) {
        if (a%2 == 1) r = max(r,tree[a++]);
        if (b%2 == 0) r = max(r,tree[b--]);
        a /= 2; b /= 2;
    }
    return r;
}

int n, q;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i,x);
    }
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        cout << getMax(a,b) << "\n";
    }
}
*/