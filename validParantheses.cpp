// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

//    Open brackets must be closed by the same type of brackets.
//    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.


class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> hash;
        hash[')'] = '(';
        hash['}'] = '{';
        hash[']'] = '[';
          
        stack<char> st;
        
        for (char c : s) {
            if (hash.find(c) != hash.end()) {
                char q = st.empty() ? '#' : st.top();
                st.pop();
                if (hash[c] != q) return false;
            } else {
                st.push(c);
            }
        }  
        return st.empty();
    }
};
