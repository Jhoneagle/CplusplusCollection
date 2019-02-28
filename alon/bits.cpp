#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string text = "god damm broken haden!";

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  set<long long> positions;
  map<long long, long long> pairs;
  multiset<long long> lengths;
  vector<long long> changes;
  string bits;
  long long amountOfChanges;
  long long temp;
  
  cin >> bits >> amountOfChanges;
  
  for (long long i = 0; i < amountOfChanges; i++) {
    cin >> temp;
    changes.push_back(temp);
  }
  
  long long counter = 1;
  char bitType = bits[0];
  
  for (long long i = 1; i < bits.size(); i++) {
    if (bits[i] == bitType) {
      counter++;
    } else {
      positions.insert(i);
      lengths.insert(counter);
      pairs[i] = counter;
      
      counter = 1;
      bitType = bits[i];
    }
  }
  
  positions.insert(bits.size());
  lengths.insert(counter);
  pairs[bits.size()] = counter;
  
  for (auto modify : changes) {
    auto lastPosOfList = positions.lower_bound(modify);
    
    cout << modify << "? " << endl;
	  
    if (lastPosOfList == positions.end()) cout << "error1"  << endl;

    if (modify == *lastPosOfList) {
      if (pairs[modify] == 1) {
        positions.erase(lastPosOfList);
	    
        auto previous = positions.find(modify - 1);
            
        if (previous != positions.end()) {
	  positions.erase(previous);
	  auto mergeEnd = positions.lower_bound(modify);
	      
          if (mergeEnd == positions.end()) cout << "error2"  << endl;
  	
          long long mergeStart = modify - 1;
          
          long long startDistance = pairs[mergeStart];
          long long endDistance = pairs[*mergeEnd];
          long long sum = startDistance + 1 + endDistance;
          pairs[*mergeEnd] = sum;
          
          auto erase = lengths.find(startDistance);
          
          if (erase == lengths.end()) cout << "error3"  << endl;
          
          lengths.erase(erase);
          erase = lengths.find(endDistance);
	  
          if (erase == lengths.end()) cout << "error4"  << endl;
           
          lengths.erase(erase);
          erase = lengths.find(1);
	  
          if (erase == lengths.end()) cout << "error5"  << endl;
          
          lengths.erase(erase);
          
          lengths.insert(sum);
	} else {
	  auto mergeEnd = positions.lower_bound(modify);
	      
          if (mergeEnd == positions.end()) cout << "error2"  << endl;
  	  
          long long endDistance = pairs[*mergeEnd];
          long long sum = 1 + endDistance;
          pairs[*mergeEnd] = sum;
          
          auto erase = lengths.find(endDistance);
	  
          if (erase == lengths.end()) cout << "error4"  << endl;
           
          lengths.erase(erase);
          erase = lengths.find(1);
	  
          if (erase == lengths.end()) cout << "error5"  << endl;
          
          lengths.erase(erase);
          
          lengths.insert(sum);
	}
      } else {
        positions.erase(lastPosOfList);
        positions.insert(modify - 1);
        
        auto nextOfModify = positions.lower_bound(modify);
        
        if (nextOfModify == positions.end()) cout << "error6"  << endl;
        
        if (nextOfModify == positions.end()) {
          positions.insert(modify);
	  
          if (pairs.find(modify) == pairs.end()) cout << "error6.5"  << endl;
         
	  long long deleteDistance = pairs[modify];
          long long subtractDistance = deleteDistance - 1;
          
          pairs[modify - 1] = subtractDistance;
          pairs[modify] = 1;
	  
          auto erase = lengths.find(deleteDistance);
	  
          if (erase == lengths.end()) cout << "error7"  << endl;
          
	  lengths.erase(erase);
          
          lengths.insert(subtractDistance);
          lengths.insert(1);
        } else {
          long long deleteDistance = pairs[modify];
          long long subtractDistance = deleteDistance - 1;
          
          if (nextOfModify == positions.end()) cout << "error7.5"  << endl;
	
          pairs[modify - 1] = subtractDistance;
          pairs[*nextOfModify]++;
          
          long long addDistance = pairs[*nextOfModify];
          long long delete2Distance = addDistance - 1;
          
          auto erase = lengths.find(deleteDistance);
	  
          if (erase == lengths.end()) cout << "error8"  << endl;
        
          lengths.erase(erase);
          erase = lengths.find(delete2Distance);
          
          if (erase == lengths.end()) cout << "error9"  << endl;
        
	  lengths.erase(erase);
          
          lengths.insert(subtractDistance);
          lengths.insert(addDistance);
	}
      }
    } else {
      auto isStartOfLine = positions.find(modify - 1);

      if (isStartOfLine == positions.end()) cout << "error10"  << endl;

      if (modify == 1 || isStartOfLine == positions.end()) {
        long long distanceOfLastPos = pairs[*lastPosOfList];
        long long startPosition = *lastPosOfList - distanceOfLastPos + 1;
        
        long long distanceUnderModify = modify - startPosition;
        long long distanceOverModify = distanceOfLastPos - distanceUnderModify - 1;
        
        pairs[modify] = 1;
        pairs[modify - 1] = distanceUnderModify;
        pairs[*lastPosOfList] = distanceOverModify;
        
        positions.insert(modify);
        positions.insert(modify - 1);
        
        auto eraseOld = lengths.find(distanceOfLastPos);
        
        if (eraseOld == lengths.end()) {
	  cout << "error11"  << endl;
	  cout << "pos: ";
	  for (auto it : positions) cout << it << " ";
	  
	  cout << endl << "length: ";	  
	  
	  for (auto it : lengths) cout << it << " ";
	  
	  cout << endl << "lpol: " << *lastPosOfList;
	  cout << " dolp: " << distanceOfLastPos << endl;
	}
	
	lengths.erase(eraseOld);
        
        lengths.insert(1);
        lengths.insert(distanceUnderModify);
        lengths.insert(distanceOverModify);
      } else {
        pairs[*lastPosOfList]--;
        long long deleteDistance = pairs[*isStartOfLine];
        long long subtractDistance = pairs[*lastPosOfList];
        long long addDistance = deleteDistance + 1;
        long long delete2Distance = subtractDistance + 1;
        
        pairs[modify] = addDistance;
        
        positions.erase(isStartOfLine);
        positions.insert(modify);
	
	auto erase = lengths.find(deleteDistance);
	
        if (erase == lengths.end()) cout << "error12"  << endl;
	
        lengths.erase(erase);
        erase = lengths.find(delete2Distance);
	
        if (erase == lengths.end()) cout << "error13"  << endl;
	
	lengths.erase(erase);
        
        lengths.insert(subtractDistance);
        lengths.insert(addDistance);
      }
    }
    
    auto wantedValue = lengths.end();
    wantedValue--;
    cout << *wantedValue << " ";
  }
  
  cout << "\n";
  return 0;
}