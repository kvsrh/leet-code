https://leetcode.com/problems/number-of-islands/

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

class Solution {
public:
    void dfs (vector<vector<char>> & grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();
        
        grid[r][c] =  '0';
        
        if (r-1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
        if (r+1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
        if (c-1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
        if (c+1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
     }
    
    int numIslands(vector<vector<char>> grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
        int num_islands = 0;
        
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++num_islands; 
                }
            }
        }
        return num_islands;
    }
};

class Solution {
    public: 
    vector<int> dirs = {0, 1, 0, -1, 0};
    
    void dfs (vector<vector<char>> & grid, int r, int  c) {
        grid[r][c] = '0';
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < dirs.size()-1; i++) {
            int nr = r + dirs[i];
            int nc = c + dirs[i+1];
            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                grid[nr][nc] == '1') {
                dfs (grid, nr, nc);
            }
        }
        return;
    }
    
    int numIslands (vector<vector<char>> & input) {
        
        int rows = input.size();
        if (rows == 0)
            return 0;
        int cols = input[0].size();
        
        int count = 0;
        
        vector<vector<char>> grid = input;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    dfs (grid, r, c);
                    count++;
                } 
            }
        }
        return count;
    }
};
