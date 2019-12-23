### ---
28. Implement strStr()
Easy

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

###  ---

static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); return 0;}();

/*
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay_size = haystack.size();
        int need_size = needle.size();
        
        if (need_size == 0) return 0;
        
        if (need_size > hay_size) return -1;
        
        int hay_index = 0;
        int need_index = 0;
        
        for (hay_index = 0; hay_index < hay_size; hay_index++) {
            int hay_start = hay_index;
            for (need_index = 0; need_index < need_size; need_index++) {
                if (hay_start < hay_size && (haystack[hay_start] == needle[need_index])) {
                    hay_start++;
                    continue;
                } else {
                    break;
                }
            }
           
            if (need_index == need_size) return hay_index;
        }
        return  -1;
    }
};

*/

// Robin Karp algorithm  
// Key idea -  generate a rolling hash.
// Once the rolling hash is a the same - we need to match character by  character. 

uint64_t startHash (string & s, int start, int end) {
    uint64_t hash = 0;
    int p = 17;
    
    for (int i = start; i < end+1; i++) {
        hash = hash+(s[i]*(pow(p, i-start)));
    }
    
    return hash;
}

uint64_t rollingHash(string & s, uint64_t prev_hash, int start, int end) {
    // Check for start and end in the range in  the calling function. 
    
    uint64_t hash = prev_hash;
    int p = 17;
    hash = (hash - s[start-1])/p;
    hash = hash + (s[end]*(pow(p,end-start)));
    return hash;
}

bool charCompare(string & hay, string & need, int start, int end) {
    int hay_s = start;
    int need_s = 0;
    while (need_s < need.size()) {
        if (hay[hay_s+need_s] == need[need_s]) {
            need_s++;
            continue;
        } else {
            break;
        }
    }
    if (need_s == need.size()) {
        return true;
    }
    return false;
}


class Solution {
public:
    int strStr(string haystack, string needle) {
    
        int hay_size = haystack.size();
        int need_size = needle.size();
        
        if (need_size == 0) return 0;
        if (hay_size < need_size) return-1;
        
        uint64_t need_hash = startHash(needle, 0, need_size-1);
        uint64_t hay_hash = 0;
        
        // hay_hash = startHash(haystack, 0, needle.length()-1);
        
        for (int i = 0; i < hay_size - need_size + 1; i++) {
            if (i == 0)  { 
                hay_hash = startHash(haystack, i, i+need_size-1);
            } else {
                hay_hash = rollingHash(haystack, hay_hash, i, i+need_size-1);
            }
            if (hay_hash == need_hash) {
                // do a char by char comparison.
                if (charCompare(haystack, needle, i ,i+need_size-1)) {
                    return i;
                }
            }
        }
        return -1;           
    }
};
