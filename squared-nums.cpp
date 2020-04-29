Problem Statement #

Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]

Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0 1 1 4 9]

using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& nums) {
    int n = nums.size();
    vector<int> squares(n);
    // TODO: Write your code here
    
    int left = 0;
    int right = n-1;
    int rightIndex = n-1;
    while (left <= right) {
        int leftNum = nums[left]*nums[left];
        int rightNum = nums[right]*nums[right];
        if (leftNum > rightNum) {
            squares[rightIndex--] = leftNum;
            left++;
        } else {
            squares[rightIndex--] = rightNum;
            right--;
        }
    }

    return squares;
  }
};
