Generate parantheses: 

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

class Solution {
  public: 
    void helper(vector<string> & result, int open, int close, int n, string s) {
        if (s.size() == 2*n) {
            result.emplace_back(s);
            return;
        }
    
        if (open < n) {
            helper(result, open+1, close, n, s+"(");
        }
        if (close < open) {
            helper(result, open, close+1, n, s+")");
        }
        return;     
    
    }
    
    vector<string> generateParenthesis(int n) {
        vector <string> result;
        string s = "";
        helper(result, 0, 0,  n, s);
        return result;
    }
    
};
