#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long n;
long long size;
vector<long long> l;
map<long long, long long> prevSum;

long long findSublaySum() {
  long long result = 0; 
  long long currsum = 0; 
  
  for (long long i = 0; i < size; i++) { 
    currsum += l[i];
    
    if (currsum == n)  result++;
    
    if (prevSum.find(currsum - n) !=  prevSum.end())  {
      result += prevSum[currsum - n]; 
    }
    
    prevSum[currsum]++; 
  } 
  
  return result; 
} 

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  long long result;
  long long v;
  cin >> size >> n;
  
  for (long long i = 0; i < size; i++) {
    cin >> v;
    l.push_back(v);
  }
  
  result = findSublaySum();
  cout << result << "\n";
  return 0;
}