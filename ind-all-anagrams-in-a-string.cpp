https://leetcode.com/problems/find-all-anagrams-in-a-string/

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // A modification of the Robin-Karp algorithm. All anagrams of p will have
        // the same rolling hash. Need not be? 
        
        // Can we use the caterpillar algorithm?
        
        int ns = s.size(); int np = p.size();
        
        vector<int> result;
        
        vector<int> pMap(26,0);
        vector<int> sMap(26,0);
        
        for (auto c : p) {
            pMap[c-'a']++;
        }
        
        for (int i = 0; i < ns; i++) {
            sMap[s[i]-'a']++;
            if (i >= np) {
                sMap[s[i-np]-'a']--;
            }
            
            if (sMap == pMap) {
                result.emplace_back(i-np+1);
            }
        }
        
        return result;
        
    }
};
