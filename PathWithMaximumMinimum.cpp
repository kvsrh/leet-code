/*
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        
        int r = A.size();
        int c = A[0].size();
        
        if (r == 0 && c == 0) return -1;
        
        int maxscore = INT_MAX;
        priority_queue<tuple<int,int,int>> q;
        q.emplace(A[0][0],0,0);
        A[0][0] = -1;
        
        while (!q.empty()) {
            auto [a,i,j] = q.top();
            q.pop();
            
            maxscore = min(a,maxscore);
            
            if (i == r-1 && j == c-1) return maxscore;
            
            if (i+1 < r && A[i+1][j] >= 0) {
                q.emplace(A[i+1][j],i+1,j); A[i+1][j] = -1;
            }
            
            if (j+1 < c && A[i][j+1] >= 0) {
                q.emplace(A[i][j+1],i,j+1); 
                A[i][j+1] = -1;
            }
            
            if (i-1 >= 0 && A[i-1][j] >= 0) {
                q.emplace(A[i-1][j],i-1,j); 
                A[i-1][j] = -1;
            }
            
            if (j-1 >= 0 && A[i][j-1] >= 0) {
                q.emplace(A[i][j-1],i,j-1); 
                A[i][j-1] = -1;
            }   
        }
        return -1;
    }
};
*/

class Solution {
    public:
int maximumMinimumPath(vector<vector<int>>& A) {
        static constexpr int DIRS[][2] {{0,1},{1,0},{0,-1},{-1,0}};
        priority_queue<tuple<int,int,int>> pq;
        pq.emplace(A[0][0], 0, 0);
        int n = A.size(), m = A[0].size(), maxscore = A[0][0];
        A[0][0] = -1; // visited
        while(!pq.empty()) {
            auto [a, i, j] = pq.top();
            pq.pop();
            maxscore = min(maxscore, a);
            if(i == n - 1 && j == m - 1)
                return maxscore;
            for(const auto& d : DIRS)
                if(int newi = d[0] + i, newj = d[1] + j;
                   newi >= 0 && newi < n && newj >= 0 && newj < m && A[newi][newj]>=0){
                    pq.emplace(A[newi][newj], newi, newj);
                    A[newi][newj] = -1;
                }
        }
        return -1; // shouldn't get here
    }
};
