Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); return 0;}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
    
        for (int i = 0 ; i < nums.size(); i++) {
            
            if  (nums[i] > 0) {
                break; 
            }
            
            // prevent if we already did a 2's sum with the same target.
            
            if (i > 0 && (nums[i] == nums[i-1])) continue;
            
            int left =  i+1;
            int right = nums.size()-1;
            int target = 0-nums[i];
            while (left < right)  {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // If we have already seen the same num[left] skip the duplicates.
                    while ((left+1 < right) && (nums[left]==nums[left+1])) left++;
                    while ((right-1 > left) && (nums[right]==nums[right-1])) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};

# notes - 1) sort the numbers.
          2) Pick a number from the nums: nums[i]. Perform 2Sum solution on the rest of the array using target as 0-nums[i]. 
          3) Don't consider duplicate answers by zapping forward through them.
          4) 
