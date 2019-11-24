// Given an array of strings, group anagrams together.
//
// Example:
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]

class Solution {

private:
    unordered_map<string, vector<string>> hash;

public:
    
    void string_cluster(string s) {
        string sort_str = s;
        sort(sort_str.begin(), sort_str.end());
        hash[sort_str].emplace_back(s);
    } 
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            for  (const auto & str : strs) {
                string_cluster(str);
            }
            vector<vector<string>> res;
            for (const  auto & str_set : hash) {
                res.emplace_back(str_set.second);
            }
        return res;
    }
};
