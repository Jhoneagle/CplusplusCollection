#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
bool sortbysec(const pair<long,string> &a, const pair<long,string> &b) { 
  if (a.first == b.first) {
    return (a.second < b.second);
  }
  
  return (a.first > b.first); 
} 

int main() {
  long long n;
  cin >> n;
  vector<pair<long,string>> v;
  string s;
  long l;

  for (long long i = 0; i < n; i++) {
    cin >> s >> l;
    v.push_back({l,s});
  }
  
  sort(v.begin(),v.end(), sortbysec);
  
  for (long long i = 0; i < n; i++) {
    cout << v[i].second << " " << v[i].first << "\n";
  }
}