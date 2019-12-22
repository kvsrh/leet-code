Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2

Example 3:

Input: [7,8,9,11,12]
Output: 1

##########

static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int negative_index = 0;
      
        for (int i = 0; i < size; i++) {
            if (nums[i] <= 0) {
              swap(nums[i], nums[negative_index]);
              negative_index++;
            }
        }
        
        int pos_max = size-negative_index;
        int j = negative_index;
        
        for (; j < size; j++) {
             if (nums[j] > pos_max) {
                
                continue;
             }
             
             while ((nums[j] != (j - negative_index + 1)) && 
                    ((nums[j] + negative_index - 1) < size)) {
                 if (nums[nums[j]+negative_index-1] != nums[j]) {
                    swap(nums[nums[j]+negative_index-1], nums[j]);
                 } else {
                     break;
                 }
             } 
        }
        
        j = negative_index;
        
        for (; j < size; j++) {
             if (nums[j] != (j-negative_index+1)) {
                 break;
             }
        }
    
        return j-negative_index+1;
    }
};

### 

The basic logic is to push all the non-positive numbers to the left and then sort all the numbers > 0  starting from the first
position when we find a non-postive number. 

###

