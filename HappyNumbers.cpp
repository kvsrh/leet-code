Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the 
sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly
in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Notes: How do we make sure the number will not increase unbounded? 
Interesting method wherein we can use the slow and fast runner method to work find a loop in the numbers we visit. 
Gay mentioned an interesting thing where in we can find out the loop if when doing the math we reach a number which is a single digit and if it is 1 or 7 it is a happy number. 

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int result = n;
        
        while (result != 1) {
            int result1 = 0;
            
            while (result > 0) {
                result1 += (result%10)*(result%10);
                result = result/10;
            }
            
            if (set.count(result1) > 0) {
                for (auto item : set) {
                    cout << item << " ";
                 }
                cout << endl << result1 << endl;
                
                return false;   
            }
               
            result = result1;
            set.insert(result1);
        }
        return true;
    }
};
