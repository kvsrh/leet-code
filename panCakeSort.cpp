
Pancake Sort
Given an array of integers arr:

Write a function flip(arr, k) that reverses the order of the first k elements in the array arr.
Write a function pancakeSort(arr) that sorts and returns the input array. You are allowed to use only the function flip you wrote in the first step in order to make changes in the array.
Example:

input:  arr = [1, 5, 4, 3, 2]

output: [1, 2, 3, 4, 5] # to clarify, this is pancakeSort's output
Analyze the time and space complexities of your solution.

Note: it’s called pancake sort because it resembles sorting pancakes on a plate with a spatula, where you can only use the spatula to flip some of the top pancakes in the plate. To read more about the problem, see the Pancake Sorting Wikipedia page.

Constraints:

[time limit] 5000ms

[input] array.integer arr

[input] integer k

0 ≤ k
[output] array.integer

#include <iostream>
#include <vector>

using namespace std;

void flip(vector<int> & arr, int k) {
  reverse(arr.begin(), arr.begin()+k); // interesting!! from beginning till the length you want to swap. 
}

int findMaxIndex (vector<int> & arr, int start, int end) {
    int max_index = -1;
    int max_elem = INT_MIN;
    
    for (int i = start; i <= end; i++) {
          if (arr[i] > max_elem) {
            max_index = i;
            max_elem = arr[i];
          }
    }
    return max_index; 
}

vector<int> pancakeSort( const vector<int>& array ) 
{
 
  vector<int> arr = array;
  int end = arr.size()-1;

  while (end > 0) {
    int j = end;
    int index = findMaxIndex(arr, 0, j);
  
    flip(arr,index+1);
    flip(arr,end+1);
    end--;
  }

  return arr;
  
}

int main() {
  return 0;
}
