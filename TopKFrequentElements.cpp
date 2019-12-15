347. Top K Frequent Elements
Medium

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

/*
bool compare (vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a hash-map first and then have a priority queue for all the elements. 
        // O(n) time complexity, O(n+k) space complexity. 
        
        unordered_map <int, int> hash;
        
        for (auto & i : nums) {
            if (hash.find(i) == hash.end()) {
                hash[i] = 1;
            } else {
                hash[i]++;
            }
        }
    
priority_queue<vector<int>, vector<vector<int>>, std::function<bool(vector<int>, vector<int>)>> pq(compare);
        
        for (auto & hash_elem : hash) {
            if (pq.size() < k) {
                pq.push({hash_elem.first,hash_elem.second});
            } else if (hash_elem.second > pq.top()[1]) {
                pq.pop();
                pq.push({hash_elem.first,hash_elem.second});
            }
        }
        
        vector<int> result;
    
        for (int i = 0; i < k; i++) {
            result.emplace_back(pq.top()[0]);
            pq.pop();
        }
        
        return result;
    }
};
*/

Fast solution:

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> v;
        unordered_map<int, int> count_map;
        for(auto n: nums) count_map[n]++;
        priority_queue<pair<int, int>> maxHeap;
        for(auto& pair: count_map) maxHeap.emplace(pair.second, pair.first);
        while(k--)
        {
            v.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return v;
    }
};
