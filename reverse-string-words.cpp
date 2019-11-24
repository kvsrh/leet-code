// Not the most optimal solution. 
// But has fance start and end manipulation. 
// The best solution is too reverse the string in place. 

#include <iostream>
#include <vector>

using namespace std;

vector<char> reverseWords(const vector<char>& arr) 
{
  // your code goes here
  
  // Go over the vector<char> and construct strings
  // which i'll push into a vector. 
  // push string into vector<char>.
 
  int size = arr.size();
  
  if (size <= 1) return arr;
  
   vector<char> res;

  int start = size-1;
  int end = size -1; 
  
  // Edge case - only one word in the input. 
  
  while (start >= 0) {
      
      while (start >= 0 && arr[start] != ' ') start--;
      
      for (int i = start+1; i <= end; i++) {
          res.emplace_back(arr[i]);
      }
      
      if (start+1 != 0) res.emplace_back(' ');
      end = start-1;
      start = start-1;
  }
  
  return res;
}
