 class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> min (nums.size(), 0);
        min[0] = nums[0];
        stack<int> s;
        for (int i = 0; i < nums.size()-1; i++) {
            min[i] = min (min[i-1],num[i]);
        }
        
        for (int i = nums.size()-1; i>= 0; i--) {
            if (nums[i] > min[i]) {
                while(!s.empty() && (s.top() < min[i]))
                    s.pop();
                if (!s.empty() && (s.top() < nums[i]))
                    return true;
            s.push(nums[i]);
        }
    }
    return false;
}

Notes: Incredible solution - 
1) Keep a rolling min list.
2) For a given index i (min[i],nums[i]) is the 13 pattern.
3) Move backwards from the right - and check for numbers in the range of the 13 pattern. 

Knuth the man - on stack sortable permutations.

