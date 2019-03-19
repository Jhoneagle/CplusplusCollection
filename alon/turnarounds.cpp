#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long number;

number n, result;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<string> strings(n + 1);
  number left[n + 1][n + 1] = {0};
  number top[n + 1][n + 1] = {0};
  
  for (number i = 1; i <= n; i++) {
    cin >> strings[i];
  }	  
  
  if (n == 1) {
    string only = strings[1];
    
    if (only[0] == '*') {
      cout << -1 << endl;
      return 0;
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  
  for (number i = 1; i <= n; i++) {
    left[i][0] = 1e11;
    left[0][i] = 1e11;
    
    top[i][0] = 1e11;
    top[0][i] = 1e11;
  }
  
  for (number y = 1; y <= n; y++) {
    string value = strings[y];
    
    for (number x = 1; x <= n; x++) {
      if (y == 1 && x == 1) {
        top[y][x] = 0;
	left[y][x] = 0;
      } else {
	if (value[x - 1] == '*') {
          left[y][x] = 1e11;
	  top[y][x] = 1e11;
        } else {
          number leftLeft = left[y][x - 1];
	  number topLeft = top[y][x - 1];
	  
	  number leftTop = left[y - 1][x];
	  number topTop = top[y - 1][x];
	  
	  number smallest = min(min(leftLeft, topLeft + 1), min(leftTop + 1, topTop));
	  
	  if (smallest == leftLeft) {
	    left[y][x] = smallest;
	    top[y][x] = topLeft + 1;
	  } else if (smallest == topTop) {
	    left[y][x] = leftTop + 1;
	    top[y][x] = smallest;
	  } else {
	    if (smallest == (topLeft + 1) && smallest == (leftTop + 1)) {
	      left[y][x] = smallest;
	      top[y][x] = smallest;
	    }else if (smallest == (topLeft + 1)) {
	      left[y][x] = smallest;
	      top[y][x] = 1e11;
	    } else if (smallest == (leftTop + 1)) {
	      left[y][x] = 1e11;
	      top[y][x] = smallest;
	    }
	  }
        }
      }
    }
  }
  /*
  cout << "debug" << endl;
  for (number i = 0; i <= n; i++) {
    for (number j = 0; j <= n; j++) {
      cout << i << " " << j << ": " << left[i][j] << " " << top[i][j] << endl;
    }
  }
  */
  result = min(left[n][n], top[n][n]);
  if (result > 1e10) result = -1;
  cout << result << endl;
  return 0;
}