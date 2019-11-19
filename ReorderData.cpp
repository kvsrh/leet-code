// ReorderLogFiles --
/*
937. Reorder Data in Log Files
Easy

You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

    Each word after the identifier will consist only of lowercase letters, or;
    Each word after the identifier will consist only of digits.

We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.
*/

#include<cctype>

class Solution {
    public:
    vector<string> reorderLogFiles (vector<string> & logs) {
        stable_sort(logs.begin(), logs.end(), myCmp);
        return logs;
    }

    static bool myCmp(const string & str1, const string & str2) {
        const char * ident1 = str1.c_str();
        const char * ident2 = str2.c_str();

        const char * data1 = strstr(ident1, " ")+1;
        const char * data2 = strstr(ident2, " ")+1;

        if (isdigit(*data1) && isdigit(*data2)) {
            return false;
        } else if (isdigit(*data1)) {
            return false;
        } else if (isdigit(*data2)) {
            return true;
        }

        int diff = strcmp(data1, data2);
        if (diff) return diff < 0;

        return strcmp(ident1, ident2) < 0;
    }
};
