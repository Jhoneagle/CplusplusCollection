#include <iostream>

using namespace std;

void loop(long long a, long long n) {
  for (long long i = a; i <= n; i += 2) {
    cout << i << " ";
  }
}

int main() {
  long long n;
  cin >> n;

  if (n == 1) {
    cout << "1";
    return 0;
  }
  
  if(n < 4) cout << "NO SOLUTION";

  if(n >= 4) {
    loop(2, n);
    loop(1, n);
  }
  
  return 0;
}