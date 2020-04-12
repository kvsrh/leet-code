844. Backspace String Compare
Easy

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:

    1 <= S.length <= 200
    1 <= T.length <= 200
    S and T only contain lowercase letters and '#' characters.

Follow up:

    Can you solve it in O(N) time and O(1) space?




class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        int indexS = S.size()-1;
        int indexT = T.size()-1;
        
        // int index = max(sizeS, sizeT); 
        
        // out << "indexS : " << indexS << " indexT : " << indexT << endl;
        
        while (indexS >= 0 || indexT >= 0) {
            int SbackCount = 0;
            int TbackCount = 0;
            
            while (indexS >= 0 && S[indexS] == '#') {
               
                while(indexS >= 0 && S[indexS] == '#') {
                    SbackCount++;
                    indexS--;
                }
                
                while (SbackCount > 0 && indexS >= 0 && S[indexS] != '#') {
                    SbackCount--;
                    indexS--;
                }
            }
            
           // cout << "S Index : " << indexS << endl;
            
            while (indexT >= 0 && T[indexT] == '#') {
                while(indexT >= 0 && T[indexT] == '#') {
                    TbackCount++;
                    indexT--;
                }
                
                while (TbackCount > 0 && indexT >= 0 && T[indexT] != '#') {
                    TbackCount--;
                    indexT--;
                }
            }
            
            // cout << "T Index : " << indexT << endl;
            
            char s = indexS < 0 ? '@' : S[indexS];
            char t = indexT < 0 ? '@' : T[indexT];
            
            // cout << "s char : " << s << "," << " t char : " << t << endl;
             
            if (s != t) {
                return false;
            } else {
                indexS--;
                indexT--;
                continue;
            } 
        }
        return true;
    }
};
