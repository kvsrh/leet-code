First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.

/*
class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,pair<int,int>> map;  // char: count, index.
                                                // Can you speed  this up any further. Not from an
                                                // Algorithmic persective. But we can use simpler data
                                                // structures for map. Like a vector of pairs. or even
                                                // simpler would be char array of size 26.
        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) != map.end()) {
                map[s[i]].first++;
                map[s[i]].second = i;
            } else {
                map[s[i]].first = 1;
                map[s[i]].second  = i;
            } 
        }
        
        uint32_t min_index = s.size();
        
        for (auto e : map) {
            if ((e.second.first == 1)  && (e.second.second < min_index)) {
                min_index = e.second.second;
            }
        }
        return (min_index == s.size()) ? -1 : min_index;
    }
};
*/

class Solution {
  public:
    int firstUniqChar(string s) {
        
        int character[26]; memset(character,0,sizeof(character));
        
        for (int i = 0; i < s.size(); i++) {
            character[s[i]-'a']++;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (character[s[i]] == 1) {
                return  i;        
            }
        }
    
        return -1;
    }
};

## Don't over use data-structures when not necessary.
