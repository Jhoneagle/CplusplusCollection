#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool create_z(string s, string p) {
  if (s == p) return true;
  int n = s.size(), m = p.size(), l = 0, r = 0;
  vector<int> z(n);
  for (int i = 0; i < n; i++) {
    z[i] = max(0, min(z[i - l], r - i));
    while (i + z[i] < n && i + m <= n && p[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] > r) {
      l = i; r = i + z[i];
    }
    if (z[i] >= m) return true;
  }
  return false;
}
 
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string p, s, res = "";
  int k;
  cin >> p >> k;
  for (int i = 0; i < k; i++) {
    cin >> s;
    if (createZ(s, p)) res += "YES";
    else res += "NO";
    res += "\n";
  }
  cout << res;
  return 0;
}