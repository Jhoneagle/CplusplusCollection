#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long number;

number n, m, x, y, z, r;
number c[501][501];
bool b[501][501] = {false};

bool maxForce(number to) {
  
}

void increaseTable(number v) {
  for (number i = 0; i < n; i++) {
    for (number j = 0; j < n; j++) {
      if (b[i][j]) {
	c[i][j] -= v;
      } else {
	c[i][j] += v;
      }
    }
  }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  
  for (number i = 0; i < m; i++) {
    cin >> y >> x >> z;
    c[y][x] = z;
    b[y][x] = true;
  }
  
  bool a = true;
  while(a) a = maxForce(1);
  
  cout << r << "\n";
  return 0;
}