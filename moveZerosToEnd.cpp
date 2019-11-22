/*
Move Zeros To End

Given a static-sized array of integers arr, move all zeroes in the array to the end of the array. You should preserve the relative order of items in the array.

We should implement a solution that is more efficient than a naive brute force.

Examples:

input:  arr = [1, 10, 0, 2, 8, 3, 0, 0, 6, 4, 0, 5, 7, 0]
output: [1, 10, 2, 8, 3, 6, 4, 5, 7, 0, 0, 0, 0, 0]
*/

#import <iostream>
#import <vector>

using namespace std;

vector<int> moveZerosToEnd(const vector<int>& array)
{
	// your code goes here
  
  vector<int> arr = array; 
  
  int zero_index = 0;
  
  int size = arr.size();
  
  if (size == 0) return array;
  int temp = 0;
  for (int array_index = 0; array_index < size; array_index++) {
      if (arr[array_index] != 0) {
        temp = arr[zero_index];
        arr[zero_index] = arr[array_index]; 
        arr[array_index] = temp;
        zero_index++;
      }
  }
