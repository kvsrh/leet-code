String to Integer (atoi)

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:

Input: "42"
Output: 42

Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.

class Solution {
public:
    
    uint32_t strToNum(string & s, int i, bool isNeg) {
        uint32_t max = 0;
        
        if (isNeg) max = (1 << 31);
        else max = (1 << 31) - 1;
        
        int size = s.size();
        uint32_t result = 0;
        
        uint32_t pre_max = max/10;
        uint32_t rem = max%10;
        
        while (i < size) {
            if (!((s[i]-'0' >= 0) && (s[i]-'9' <= 0))) break; 
            if ((result > pre_max)) return max; // important steps to prevent overflow. 
            if ((result == pre_max) && ((s[i]-'0')) > rem) return max; // important steps to prrevent overflow;
            result = 10*result + (s[i]-'0');
            i++;
        }
        return  result;
    }
    
    int myAtoi(string str) {
        bool isNeg = false;
        int i = 0;
        for (char c : str) {
            i++;
            if  (c == ' ') {
                continue;
            }
            if (c == '-') {
                isNeg = true;
                break;
            }
            
            if (c == '+') {
                break;
            }
            
            if (c-'0' >= 0 && c-'9' <= 0) {
                i--;
                break;
            }
            
            // If we have come here, we have encountered an non-space and non-digit 
            // character. return with 0.
            
            return 0;
        }    
        
        uint32_t result =  strToNum(str, i, isNeg);
    
        // This can be made better by representing the number in the 
        // form  of 2's complement. 
        
        int64_t res = 0; 
        
        if (isNeg)  res = 0-result;
        else res = result;
        return res;
    }
};
