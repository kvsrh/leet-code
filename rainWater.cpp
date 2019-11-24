// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it is able to trap after raining.

#include<algorithm>

class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int size = height.size();
        
        if (size == 0) return water;

        vector<int> maxLeft = vector(size,0);
        vector<int> maxRight = vector(size,0);
        
        maxLeft[0] = height[0];
        maxRight[size-1] = height[size-1];
        
        for (int i = 1; i < size; i++) {
            maxLeft[i] = max(maxLeft[i-1], height[i]); 
        }
        
        for (int j = size-2; j >=0; j--) {
            maxRight[j] = max(maxRight[j+1], height[j]);
        }        
        
        for (int i = 0; i < size; i++) {
            water += (min(maxLeft[i], maxRight[i]) - height[i]);
        }
        return water;    
    }
};
