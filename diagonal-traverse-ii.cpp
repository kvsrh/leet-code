
1424. Diagonal Traverse II
Medium
Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.

Example 1:

Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]

Example 2:

Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]

Example 3:

Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
Output: [1,4,2,5,3,8,6,9,7,10,11]

Example 4:

Input: nums = [[1,2,3,4,5,6]]
Output: [1,2,3,4,5,6]

 

Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i].length <= 10^5
    1 <= nums[i][j] <= 10^9
    There at most 10^5 elements in nums.

/*
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        cout << "rows : " << nums.size();
        
        int maxCols = 0;
        
        for (auto row : nums) {
            maxCols = row.size() > maxCols ? row.size() : maxCols;
        }
        
          cout << "cols : " << maxCols;
        
        return {};
        
        
        int count = 0;
        
        vector<int> result;
        
        int rowSize = nums.size();
        
        int colMax = 0;
        //int rowMax = 0;
        
        if (rowSize == 0) return {};
        
        // cout << "start" << endl;
        
        for (int row = 0; row < rowSize; row++) {
            count += nums[row].size();
            if (nums[row].size() > colMax) {
                colMax = nums[row].size();
                // rowMax = row;  
            }
            // colMax = max(colMax,nums[row].size());
            int c = 0;
            int r = row;
            while (r >= 0) {
                if (c < nums[r].size()) {
                    result.emplace_back(nums[r][c]);
                }
                r--; c++;
            }
            cout << "row : " << row << endl;
        }
        cout << "count : " << count << endl;
        
        int col = 0;
        for (col = 1; col < colMax; col++) {
            int c = col;
            int r = rowSize-1;
            if (result.size() == count) {
                break;
            }
            while (r >=0) {
                if (c < nums[r].size()) {
                    result.emplace_back(nums[r][c]);
                }
                r--;c++;
            }
            cout << result.size() << endl;
        }
        //cout << "column : " << col << endl;
        return result;
    }
};

*/

bool func (vector<int> a, vector<int> b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    } else {
        return a[1] < b[1];
    }
}

class Solution {
    public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums)  {
        
        int size = nums.size();
        
        if (size == 0) return {};
        
        vector<vector<int>> array; // array of tuple v[0] - r+c, v[1] - c, v[2] - val
        
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < nums[row].size(); col++) {
                array.push_back({row+col,col,nums[row][col]});
            }
        }
        
        sort(array.begin(), array.end());
        
        // cout << "count : " << array.size() << endl; 
        
        vector<int> result;
        
        for (auto record : array) {
            result.emplace_back(record[2]);
        }
        
        
        return result;
    }
};


/*  
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<pair<int, int>, int>> a;
        for (int x = 0; x < nums.size(); x++) {
            for (int y = 0; y < nums[x].size(); y++) {
                a.emplace_back(make_pair(x + y, y), nums[x][y]);
            }
        }
        sort(a.begin(), a.end());
        vector<int> ans;
        for (auto& p: a)
            ans.push_back(p.second);
        
        return ans;
    }
};
*/

Notes : Very fincky problem. 
1) His solution to optimize seems to be to make sure the emplace_back is faster then push_back. 
2) How the hell did sort work? How come it has the correct sorting order!!! don't understand one bit. Need to see the underneath thing. 
3) Get back to it with a question on stackoverflow.
