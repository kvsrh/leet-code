76. Minimum Window Substring
Hard

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Note:

    If there is no such window in S that covers all characters in T, return the empty string "".
    If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

##

static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); return 0;}();
/*
int mapMinLen(unordered_map<char, int> hash) {
    
    vector<int> index;
    
    for (auto e : hash) {
        index.emplace_back(e.second);
    }
       
    sort(index.begin(), index.end());     
    
    return index[0]; 
}
class Solution {
public:
    
    // Create a  hash with the char and the index at which we find the char.
    
    string minWindow(string s, string t) {
        
        int size_s = s.size();
        int size_t = t.size();
        
        if (size_t > size_s) return "";
        
        uint8_t len_min = -1;
        int min_index = 0;
        
        vector<int> result_index (2,-1);
        
        unordered_map<char, pair<int,int>> window; // k: character, v: (count, index)
        
        unordered_map<char> target;
        
        for (char c : t) {
            if (target.find(c) != target.end()) {
                target[c]++;   
            } else {
                target[c] = 1;
            }
        }

        for (int i = 0; i < size_s; i++) {
            char c = s[i];
            if (target.find() != target.end()) { // skip a char if not present in target.
                if ()
            }
            
        }
        
        // cout << "result - [" << result_index[0] << "," << result_index[1] << "]" << endl;
        
        return string(s.begin()+result_index[0], s.begin()+result_index[1]+1);
    }
};
/*
for (int i = 0; i < size_s; i++) {
            
            
            
            
             if (set.count(s[i]) > 0) {
                 hash[s[i]] = i;
                 //cout <<  "hash_size - " << hash.size() << " size_t - " << size_t << endl;
                 if (hash.size() == size_t) {
                    // cout << "### i - " << i << "###" << endl;
                     min_index = mapMinLen(hash);
                     if ((i-min_index+1) < len_min) {
                         result_index[0] = min_index;
                         result_index[1] = i;
                     }
                     hash.erase(s[min_index]); 
                 }   
             }
        }
        
*/

class Solution {
public:
  string minWindow(string  s, string t) {
      int size_s = s.size();
      int size_t = t.size();
      
      if (size_t > size_s) return  "";
      
      uint32_t min_length = -1;
      vector<int> result (2,-1);
      
      unordered_map<char,int> window;
      unordered_map<char,int> target;
      
      for (char c : t) {
          if (target.find(c) != target.end()) {
              target[c]++;
          } else {
              target[c] = 1;
              window[c] = 0; // Initialize all the window entries too here.
          }
      }
      
      int letterCount = 0; 
      
      for (int start = 0, end = 0; end < size_s; end++) {
          char c = s[end];
          if (target.find(c) != target.end()) {
              window[c]++;
              
              if (window[c] <= target[c]) {
                letterCount++;
              }
              
              if (letterCount == size_t) {
                  while (true) { 
                      if(window.find(s[start]) == window.end()) {
                          start++;
                      } else if (window[s[start]] > target[s[start]]) {
                          window[s[start]]--;
                          start++;
                      } else {
                          window[s[start]]--;
                          break;
                      }
                  }
                  
                  if ((end-start+1) < min_length) {
                      min_length = end - start + 1;
                      result[0] = start;
                      result[1] = end;
                  }
                  
                  letterCount--; 
                  start++;
              }
          }
      }
      return string (s.begin()+result[0], s.begin()+result[1]+1);
  }
};

# Notes #

we are using two hashes windows and target. The target keeps a context of the maximum value of each character in the target
string t. 
