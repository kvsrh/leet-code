class Solution {
public:
    string decodeString(string s) {
        // Stack based solution.
        
        stack<char> stk;
        string result = "";
        
        for (char c : s) {
            if  (c != ']') {
                stk.push(c);
            } else {
                string temp = "";
                while (stk.top() != '[') {
                    temp = stk.top() + temp;
                    stk.pop();
                }
                stk.pop(); // Remove the '[' from the top of the stack.
                //int count = atoi(&stk.top()); // What line.
                //cout << "### " << count << "###" << endl; 
                //stk.pop(); // Remove the count from the stack. ?? Does it have to be only a single digit.
                
                string count_str = "";
                
                while (!stk.empty() && stk.top()-'0' >= 0 && stk.top()-'9' <= 9) {
                    count_str = stk.top() + count_str;
                    stk.pop();
                }
                
                int count = stoi(count_str);
                
                // push temp count times. 
                while (count > 0) {
                    for (char c : temp) {
                        stk.push(c);
                    }
                    count--;
                }
            }
        }
        
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        
        return result;
    }
};

PLEASE CONSIDER ALL TEST CASES BEFORE CODING !!! 

MADE ANOTHER MISTAKE WHEN NOT CONSIDERING THE FACT THAT THE LENGTH OF THE REPETITION STRING CANN'T BE MORE THAN A SINGLE
CHARACTER.
