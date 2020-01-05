Smallest Substring of All Characters

Given an array of unique characters arr and a string str, Implement a function getShortestUniqueSubstring that finds the smallest substring of str containing all the characters in arr. Return "" (empty string) if such a substring doesn’t exist.

Come up with an asymptotically optimal solution and analyze the time and space complexities.

Example:

input:  arr = ['x','y','z'], str = "xyyzyzyx"

output: "zyx"

Constraints:

    [time limit] 5000ms

    [input] array.character arr
        1 ≤ arr.length ≤ 30

    [input] string str
        1 ≤ str.length ≤ 500

    [output] string

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include<unordered_map>


using namespace std;

string getShortestUniqueSubstring( const vector<char>& arr, const string &str ) 
{
  // your code goes here
  // set (all elements arr)
  // hash_map K : arr[0..n-1] : count
  /*
  xyyzyzyy
       s
          e
         c       
  xyyz 
  */
  
  unordered_set<char> set (arr.begin(), arr.end());
  
  cout << set.size() << endl;
  
  unordered_map<char, int> hash;
  
  int start = 0;
  int end = str.size();
  
  if (end == 0) return "";
  
  int curr = start;
  int minL = INT_MAX;
  string result = ""; 
  
  while (curr < end) { //
      if (set.find(str[curr]) != set.end()) {
          if (hash.find(str[curr]) == hash.end()) {
            hash[str[curr]] = 1;
          } else {
            hash[str[curr]]++;
          }
          // cout << "hash-size - " << hash.size() << " curr - " << curr << endl;
          if (hash.size() == set.size()) {
            cout << " Found a match" << endl;
              while (start < end) {
                
                /* */
                if (hash.find(str[start]) != hash.end()) {
                   // xyyzyzxyyzz
                   //    c
                   //  s 
                   //                 
                    if (hash[str[start]] == 1) {
                        hash.erase(str[start]);
                        start++;
                        break;
              
                    } else {
                        hash[str[start]]--;
                    }
                }
                start++;
              } 
            // str is between start and curr.
            // cout << "###" << curr << " " << start << "###" << endl;
            if (curr-start+2 < minL) {
                minL = curr-start + 2;
                result = str.substr(start-1, curr-start+2);
                cout << result;
            } 
          }
          curr++; 
      } else {
        curr++;
      }
       /*
       curr--;   
       if (curr-start+1 < min) {
           min = curr-start+1;
           result = str.substr(start, curr-start+1);
       } 
       */
          
    }
  return result;  
}

int main() {
  return 0;
}
