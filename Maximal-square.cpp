Maximal Square --

221. Maximal Square
Medium

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        
        if (rows == 0) return 0;
        
        int cols = matrix[0].size();
        
        int dp[rows][cols];
        
        int maxL = 0;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (r == 0 || c == 0) { // Filling up the 1st row and 1st col. 
                    dp[r][c] = (matrix[r][c]-'0' == 0) ? 0 : 1;
                } else { // Filling up the non 1st and 2nd columns. 
                    if (matrix[r][c]-'0' == 1) {
                        dp[r][c] = min(min(dp[r-1][c],dp[r][c-1]),dp[r-1][c-1]) + 1;
                    } else {
                        dp[r][c] = 0;
                    }
                }
                maxL = max(maxL, dp[r][c]);
            }
        }
        
//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 cout << dp[r][c] << " ";
//             }
//             cout << endl;
//         }
        
        return maxL*maxL;
    }
};
