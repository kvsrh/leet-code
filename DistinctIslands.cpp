694. Number of Distinct Islands
Medium

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:

11000
11000
00011
00011

Given the above grid map, return 1.

Example 2:

11011
10000
00001
11011

Given the above grid map, return 3.

Notice that:

11
1

and

 1
11

are considered different island shapes, because we do not consider reflection / rotation.

Note: The length of each dimension in the given grid does not exceed 50. 

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        unordered_set<string> islands;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    string island;
                    distinct(grid, i, j, i, j, island);
                    islands.insert(island);
                    // cout << "### " << island << " ###" << endl; 
                }
            }
        }
        return islands.size();
    }
private:
    void distinct(vector<vector<int>>& grid, int i, int j, int r, int c, string& island) {
        int m = grid.size(), n = grid[0].size();
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {
            grid[r][c] = 0;
            island += to_string(r - i) + to_string(c - j);
            distinct(grid, i, j, r - 1, c, island);
            distinct(grid, i, j, r + 1, c, island);
            distinct(grid, i, j, r, c - 1, island);
            distinct(grid, i, j, r, c + 1, island);
        }
    }
};
