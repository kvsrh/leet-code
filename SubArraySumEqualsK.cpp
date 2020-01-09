560. Subarray Sum Equals K
Medium

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

Note:

    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int size = nums.size();
        if (size == 0) return -1;
        if (size == 1 && (nums[0] == k))
            return 1;
        
        unordered_map<int, int> hash;
        
        // vector<int> sum (size, -1); 
        
        int sum = 0;
        
        hash[0] = 1; 
        
        // sum[0] = nums[0];
        
        int count = 0;
        
        for (int i = 0; i < size; i++) {
            
            if (i > 0) {
                sum = sum + nums[i];
            } else {
                sum = nums[i];
            }
            
            if (hash.find(sum-k) != hash.end()) {
                count += hash[sum-k];
            }
            
            if (hash.find(sum) != hash.end()) {
                hash[sum]++;
            } else {
                hash[sum] = 1;
            } 
        }
        
        /*
        for (int j = 0; j < size; j++) {
            if (hash.find(sum[j]-k) != hash.end()) {
                int low_index = hash[sum[j]-k];
                if (low_index < j) {
                    count++;
                } 
            }
        }
        */        
        
        return count; 
    }
};
