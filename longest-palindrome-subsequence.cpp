/*
Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

#include<utility>

class Solution {
public:
    int expandAroundCenter(string s, int i, int j) {
        int left = i;
        int right = j; 
        
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--; right++;
        }
        return right - left - 1;
    }
    
    string longestPalindrome(string s) {
        
        int size = s.size();
        
        if (size == 0 || size == 1) return s;
        
        
        int len1 = 0;
        int len2 = 0;
        
        int start = 0;
        int end = 0;
        
        int len = 0;
        
        for (int  i = 0; i < size; i++) {
            // Consider an odd palindrome centered at i, and 
            // an even-length palindrome centered around [i,i+1]
            len1 = expandAroundCenter(s,i,i);
            len2 = expandAroundCenter(s,i,i+1);
            
            len = max(len1, len2);
            
            if (len > end - start) {
                start = i - (len - 1)/2;
                end = i +  len/2;
            }
        }             
        return s.substr(start, end-start+1);
    }
};
