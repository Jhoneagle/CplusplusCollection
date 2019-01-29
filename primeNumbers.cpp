#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

bool prime(long long n) {
  if (n <= 3) {
    return (n > 1);
  } 
  
  if (((n % 2) == 0) || ((n % 3) == 0)) {
    return false;
  }
  
  long i = 5;
  
  while ((i * i) <= n) {
      if (((n % i) == 0) || ((n % (i + 2)) == 0)) {
          return false;
      }

      i += 6;
  }
  
  return true;
}

int main() {
  long long n;
  cin >> n;
  
  if (prime(n + 1)) {
    for(long long i = 1; i <= n; i++) {
      cout << i << " ";
    }
 
    cout << "\n";
 
    for(long long j = n; j > 0; j--) {
      cout << j << " ";
    }
  } else {
    long long r;
    long long s;
    vector<long long> second;
    long long i = n; //asked number
 
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
      
      i = (r - 1);
      
      if (i == 3) {
        second.push_back(2);
        second.push_back(3);
        second.push_back(1);
	break;
      } else if (i == 2) {
        second.push_back(1);
        second.push_back(2);
	break;
      } else if (i == 1) {
        second.push_back(1);
	break;
      }
    }
 
    for(long long j = n; j > 0; j--){
      cout << j << " ";
    }
 
    cout << "\n";
 
    for(long long j = 0; j < n; j++) {
      long long number = second[j];
      cout << number << " ";
    }
  }
    
  return 0;
}
