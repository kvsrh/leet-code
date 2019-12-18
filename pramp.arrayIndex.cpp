Pramp Question: Array Index & Element Equality

Given a sorted array arr of distinct integers, write a function indexEqualsValueSearch that returns the lowest index i for which arr[i] == i. Return -1 if there is no such index. Analyze the time and space complexities of your solution and explain its correctness.

Examples:

input: arr = [-8,0,2,5]
output: 2 # since arr[2] == 2

input: arr = [-1,0,3,6]
output: -1 # since no index in arr satisfies arr[i] == i.


int indexEqualsValueSearch(const vector<int> &arr) 
{
  // your code goes here
  // if at arr[mid] == mid --> return mid
  // arr[0] .. arr[mid] < mid 
  int start = 0;
  int end = arr.size()-1;
  
  int mid = 0;   
  
  while (start <= end) {
      mid = start + (end - start)/2;
      if (mid == arr[mid]) {
          // Consider the case of only one element.
          while (mid >= 0 && mid == arr[mid]) { // Made this mistake when I didn't check how far can mid be decremented. 
              mid--;
          }
          return mid+1;  
      } else if (mid < arr[mid]) {
        end = mid-1;
      } else {
        start = mid+1;
      }
  }
  return -1;
}

Note: There are no duplicates in the code and the array is sorted. 

Notes: The key idea is if arr[mid] > mid then all elements to the right of mid have to be greater than arr[mid]+1 and therefore
we can never have a case where arr[mid] == mid. Therefore we move the left.
1) arr[mid+1] ... arr[end] > arr[mid]
2) arr[mid] > mid 

There is no way you could have a number to the right of mid with values - arr[i] == i.

[-3, 0, 2, 4, 7, 9, 10] 
