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

class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> map;
        vector<vector<string>> result;
        
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            
            if (!map.count(temp)) {
                map[temp] = result.size();    
                result.push_back({});
            } 
            result[map[temp]].push_back(strs[i]);
        }
        return  result;
    }
};

Notes: We previously used a hash which isn't necessary. We could use a map to store the index in the result index where all 
the strings are with the same anagram pattern are inserted in the results vector.
