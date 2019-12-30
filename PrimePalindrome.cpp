#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int evenPalindrome(int num) {
        string str1 = to_string(num);
        string str2 = str1;
        reverse(str2.begin(), str2.end());
        return stoi(str1 + str2);
    }

    int oddPlaindrome(int num) {
        string str1 = to_string(num);
        string str2 = str1.substr(0, str1.length() - 1);
        reverse(str2.begin(), str2.end());
        return stoi(str1 + str2);
    }

    bool isPrime(int num) {
        if (num == 1) {
            return false;
        }
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int primePalindrome(int N) {
        int even = 1;
        int odd = 1;

        int cur = 0;
        do {
            int evenp = evenPalindrome(even);
            int oddp = oddPlaindrome(odd);
            cur = min(evenp, oddp);
            if (evenp < oddp) {
                ++even;
            } else {
                ++odd;
            }
        } while (!(cur >= N && isPrime(cur)));

        return cur;
    }
};

#if DEBUG
int main(int argc, char** argv) {
    return 0;
}
#endif
