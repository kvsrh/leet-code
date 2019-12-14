167. Two Sum II - Input array is sorted
Easy

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

    Your returned answers (both index1 and index2) are not zero-based.
    You may assume that each input would have exactly one solution and you may not use the same element twice.


class Solution {
public:
vector<int> twoSum(vector<int>& numbers, int target) {
        // Binary search -- 
        // Perint form binary search on the two numbers: 
       
        int size = numbers.size();
        
        int left = 0; 
        int right = size-1;
        
        int sum = 0;
        
        while (left < right) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left+1, right+1};
            } else if (sum < target) {
                left++;       
            } else {
                right--;
            }    
        }
        
        return {};
        
    }
};

Notes: 

If we declare the int sum inside the while loop - the runtime falls to 56%. Outside the while loop the runtime drops to 96%. 
