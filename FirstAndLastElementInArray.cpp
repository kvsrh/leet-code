34. Find First and Last Position of Element in Sorted Array
Medium

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return {-1,-1};
        int start = 0;
        int end = size-1; // end should be the last accessible index.
        
        while (start <= end) { // start < end or start <= end ? 
            int mid = start + (end-start)/2;
        
            if (nums[mid] == target) {
                cout << mid << endl;
                int s = mid;
                
                while (s >= 0) {
                    if (nums[s] == target) {
                        s--;
                    } else {
                        break;
                    }
                }
                
                int e = mid;
                
                while (e < size) {
                    if (nums[e] == target) {
                        e++;
                    } else {
                        break;
                    }
                }
                
                return {s+1, e-1};
                
            } else if (nums[mid] > target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return {-1,-1};
    }
};
