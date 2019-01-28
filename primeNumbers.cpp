#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

bool prime(long long n) {
  bool isPrime = true;
  
  for(long long i = 2; i <= (n / 2); i++) {
    if(n % i == 0) {
      isPrime = false;
      break;
    }
  }
  
  return isPrime;
}

int main() {
  long long n;
  cin >> n;
  vector<long long> second;
  
  if (prime(n + 1)) {
    for(long long i = 1; i <= n; i++){
      cout << i, cout << " ";
    }

    cout << "\n";

    for(long long j = n; j > 0; j--) {
      cout << j, cout << " ";
    }
  } else if (((n + 1) != 0) && (((n + 1) &((n + 1) - 1)) == 0)) {
    long long r = 1;
    long long i = 1;
    long long s = 1;

    while(i <= n) {
      for (long long a = 0; a < r; a++) {
        second.push_back(s - a);
      }
      
      i += r;
      r *= 2;
      s = (i - 1) + r;
    }

    for(long long j = 1; j <= n; j++){
      cout << j, cout << " ";
    }

    cout << "\n";

    for(long long j = 0; j < n; j++) {
      long long number = second[j];
      cout << number, cout << " ";
    }
  } else {
    long long r;
    long long s;
    long long i = n;

    while(i > 0) {
      for(long long a = (i - 1); a >= 1; a--) {
        if (prime(a + i)) {
          r = a;
        }
      }
      
      s = i - r;
      
      for (long long a = 0; a <= s; a++) {
        second.push_back(r + a);
      }
      
      i -= r;
      
      if (r == 3) {
        second.push_back(1);
        second.push_back(2);
	break;
      } else if (r == 2) {
        second.push_back(1);
	break;
      }
    }

    for(long long j = n; j > 0; j--){
      cout << j, cout << " ";
    }

    cout << "\n";

    for(long long j = 0; j < n; j++) {
      long long number = second[j];
      cout << number, cout << " ";
    }
  }
    
  return 0;
}
