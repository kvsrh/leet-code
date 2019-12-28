1298. Maximum Candies You Can Get from Boxes
Hard

Given n boxes, each box is given in the format [status, candies, keys, containedBoxes] where:

    status[i]: an integer which is 1 if box[i] is open and 0 if box[i] is closed.
    candies[i]: an integer representing the number of candies in box[i].
    keys[i]: an array contains the indices of the boxes you can open with the key in box[i].
    containedBoxes[i]: an array contains the indices of the boxes found in box[i].

You will start with some boxes given in initialBoxes array. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.

Return the maximum number of candies you can get following the rules above.

 

Example 1:

Input: status = [1,0,1,0], candies = [7,5,4,100], keys = [[],[],[1],[]], containedBoxes = [[1,2],[3],[],[]], initialBoxes = [0]
Output: 16
Explanation: You will be initially given box 0. You will find 7 candies in it and boxes 1 and 2. Box 1 is closed and you don't have a key for it so you will open box 2. You will find 4 candies and a key to box 1 in box 2.
In box 1, you will find 5 candies and box 3 but you will not find a key to box 3 so box 3 will remain closed.
Total number of candies collected = 7 + 4 + 5 = 16 candy.



static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int maxCandies(vector<int>& status, 
                   vector<int>& candies, 
                   vector<vector<int>>& keys, 
                   vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) {
        
        unordered_set<int> keys_set; 
        unordered_set<int> unOpenedBoxes;
        queue<int> q; // open boxes.
        
        int candyCount = 0;
        
        for (auto box : initialBoxes) {
            
            if (status[box] == 1) {
                q.push(box);
            } else {
                unOpenedBoxes.insert(box);            
            } 
        }    
        
        while (!q.empty()) {
            auto box = q.front();
            q.pop();
            // cout  << "Opening box - " << box << endl;
            
            status[box] = 1;
            // unOpenedBoxes.erase(box); // what if the box was open from beginning?
            keys_set.erase(box);
            
            candyCount += candies[box];
            
            for (auto key : keys[box]) {
                keys_set.insert(key);
                if ((unOpenedBoxes.count(key) > 0) && (status[key] == 0)) {
                     q.push(key);
                     unOpenedBoxes.erase(key);
                     // keys_set.erase(key); // Doubtful?
                }   
            }
            
            
            for (auto nextBox : containedBoxes[box]) {
                if (status[nextBox] == 1) {
                    q.push(nextBox);
                } else if ((keys_set.count(nextBox) > 0) && (status[nextBox] == 0)) {
                    q.push(nextBox);
                } else {
                    unOpenedBoxes.insert(nextBox);
                }
            }
        }
        return candyCount;
    }
};

