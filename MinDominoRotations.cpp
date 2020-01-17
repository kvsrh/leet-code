1007. Minimum Domino Rotations For Equal Row
Medium

In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the i-th domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

Notes: Unecessarily made it complicated with trying to a single pass. Keep it simple nana. 

/*
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        int size = A.size();
        
        if (size == 0) return -1;
        
        unordered_map<int, pair<int,int>> map;
        
        map[A[0]] = make_pair(1,0);
        
        if (map.find(B[0]) != map.end()) {
            map[B[0]].first--;
        } else {
            map[B[0]] = make_pair(0,1);
        }
        
        for (int i = 0; i < size; i++) {
            if (map.find(A[i]) == map.end() &&
                map.find(B[i]) == map.end()) {
                return -1;
            }
            
            if (A[i] == B[i]) {
                continue;
            }
            
            if (map.find(A[i]) != map.end()) {
                map[A[i]].first++;
            }
            
            if (map.find(B[i]) != map.end()) {
                map[B[i]].second++;
            }
            // cout << A[0] << endl;
            if (map.find(A[0]) != map.end() && (map[A[0]].first + map[A[0]].second < i+1)) {
                map.erase(A[0]);
            }
            // cout << B[0] << endl;
            if (map.find(B[0]) != map.end() && (map[B[0]].first + map[B[0]].second < i+1)) {
                map.erase(B[0]);
            }
            cout << "i - " << i << " size - " << map.size() << endl;
        }
        
        //cout << map[A[0]].first << map[A[0]].second << endl;
        //cout << map[B[0]].first << map[B[0]].second << endl;
        cout << map.size() << endl;
        int minR = INT_MAX;
        
        for (auto e : map) {
            cout << "val - " << e.first << " Acount - " << e.second.first << "Bcount - " << e.second.second << endl;
            int minA =  min(e.second.first, e.second.second);
            minR = min(minR,minA);
        }
        
        return minR;
    }
};

*/

class Solution {
    public: 
        int minDominoRotations(vector<int> & A, vector<int> & B) {
            int size = A.size(); 
            if (size == 0) return -1;
            
            int aLow = 0;
            int aHigh = 0;
            int i;
            for (i = 0; i < size; i++) {
                
                if (A[i] != A[0] && B[i] != A[0]) {
                    break;
                }
                
                if (A[i] == A[0] && (A[i] == B[i])) {
                    continue;   
                }
                
                if (A[i] == A[0]) {
                    aHigh++;
                }
                
                if (B[i] == A[0]) {
                    aLow++;
                } 
             } 
            int bLow = 0;
            int bHigh = 0;
            int j;
            for (j = 0; j < size; j++) {
                if (A[j] != B[0] && B[j] != B[0]) {
                    break;
                }
                
                if (A[j] == B[0] && (A[j] == B[j])) {
                    continue;   
                }
                
                if (A[j] == B[0]) {
                    bHigh++;
                }
                
                if (B[j] == B[0]) {
                    bLow++;
                }
            }
            
           // if (i < size && j < size) {
           //     return -1;
           // }
            // cout << aLow << " " << aHigh << " " << bLow << " " << bHigh << endl;
            // cout << i << " " << j << endl;
            int minBSwap = (j == size) ? min(bLow, bHigh) : INT_MAX;
            int minASwap = (i == size) ? min(aLow, aHigh) : INT_MAX;
            // cout << minASwap << " " << minBSwap << endl;
            
            int result = min (minASwap, minBSwap);
            
            return result == INT_MAX ? -1 : result;
            
        }
};

