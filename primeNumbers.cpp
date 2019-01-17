#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<bool> primes(n * n, true);
  vector<bool> visits(n * n, false);

  for(int i = 2; (i * 2) <= (n * n); i++) {
    for(int j = 2; (j * i) <= (n * n); j++) {
        primes[j * i] = false;
    }
  }
  
  for(int i = 1; i <= n; i++){
    cout << i, cout << " ";
  }
  
  cout << "\n";
  
  for(int i = 1; i <= n; i++){
    for(int j = n; j >= 1; j--){
      if((primes[j + i] == true) && (visits[j] == false)) {
        cout << j, cout << " ";
	visits[j] = true;
	break;
      }
    }
  }
  
  return 0;
}
