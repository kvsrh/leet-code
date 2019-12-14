56. Merge Intervals
Medium

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

class Solution {
public:
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Are the intervals sorted by there first element. If not sort them. 
        
        sort(intervals.begin(), intervals.end());
        
        int size = intervals.size();
        
        if (size <= 1) return intervals;
        
        vector<vector<int>> result; // Be careful of what you are initalizing.
        
        result.push_back(intervals[0]);
        
        int result_idx = 0;    
            
        for (int i = 1; i < size; i++) {
            if (intervals[i][0] <= result[result_idx][1]) {
                result[result_idx][1] = intervals[i][1] > result[result_idx][1] ? intervals[i][1] : result[result_idx][1];
            } else {
                result.push_back(intervals[i]);   
                result_idx++;
            }
        }   
    
        return result;
    }
};

Notes: There was am major surprise in the run-time performance when I has initalized the result vector to {} vs not giving a
default constructor. 

Line 34: vector<vector<int>> result = {} vs vector<vector<int>> result.

case1: 76 ms, 26 Mb.
case2: 16 ms, 12.5 Mb.
