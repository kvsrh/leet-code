239. Sliding Window Maximum
Hard

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); return 0;}();
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int nums_size = nums.size();
        int end = 0;
        priority_queue<int, vector<int>> q; // max-heap.
        unordered_map <int,int> discard_hash; // num[i]:count
        
        
        int start = 0;
        
        vector<int> result;
        
        if (nums_size == 0) return result;
        
        for (int i = 0 ;  i < k && i < nums_size; i++) {
            q.push(nums[i]);
        }
        
        end = k-1;
        
        while (end < nums_size) {
            // while (q.size() < k) {
                
            // }
            // q.push(nums[end]);
            while (discard_hash.find(q.top()) != discard_hash.end()) {
                if (discard_hash[q.top()] == 1) {
                    discard_hash.erase(q.top());
                } else{
                    discard_hash[q.top()]--;
                }
                q.pop();
            }
            
            result.emplace_back(q.top()); 
            // pop the first element q.pop();
            // q.remove(nums[start]);
            
            if (discard_hash.find(nums[start]) != discard_hash.end()) {
                discard_hash[nums[start]]++;
            } else {
                discard_hash[nums[start]] = 1;
            }
            
            start++;
            end++;
            if (end < nums_size) q.push(nums[end]);
        } 
        
        return result;  
    }
};
*/

// DP solution 

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int nums_size = nums.size();
            
            if (nums_size == 0) return {};
            
            vector<int> left (nums_size,0);
            vector<int> right (nums_size, 0);
            vector<int> result (nums_size-k+1, 0);
            
            for (int i = 0; i < nums_size; i++) {
                 if ((i%k) == 0) {   
                    left[i] = nums[i];
                 } else {
                     left[i] = max(left[i-1], nums[i]);
                 }
            }
            
            for (int i = nums_size-1; i >= 0; i--) {
                if (i == nums_size-1 || (i%k == k-1))  {
                    right[i] = nums[i];
                } else {
                    right[i] = max(right[i+1], nums[i]);
                }
            }
            
            for (int i = 0; i < nums_size - k + 1; i++) {
                 result[i] = max(right[i], left[i+k-1]);
            }
            
            return result;
        }  
};
