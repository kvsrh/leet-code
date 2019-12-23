You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); return 0;}();
class Solution {
public:
    
    void fourSwap (vector<vector<int>> & matrix, int r, int c) {
        
        int row_size =  matrix.size();
        int col_size = matrix[0].size();
        
        int temp1 = 0;
        int temp2 = 0; 
        
        int count = 0;
        
        int src_row = r;
        int src_col = c;
        
        int dest_row = 0;
        int dest_col = 0;
        
        temp2 = matrix[src_row][src_col];
        
        while (count < 4)  {
            
            dest_row = src_col;
            dest_col = col_size - 1 - src_row;
            
            temp1 = temp2;
            temp2 = matrix[dest_row][dest_col];
            
            matrix[dest_row][dest_col] = temp1;
            
            src_row = dest_row;
            src_col = dest_col;
                
            count++;
        }
        return;    
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int row = 0; row < size/2; row++) {    
            for (int col = row; col < size-row-1; col++) {
                fourSwap(matrix, row, col);           
            }
        }    
        return;
    }
};


// Simpler solution to write - first perform a transpose and then reverse each of the rows in the matrix.  

class Solution {
public:
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
};

