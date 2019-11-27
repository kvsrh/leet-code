/* K-Messed Array Sort
Given an array of integers arr where each element is at most k places away from its sorted position, code an efficient function sortKMessedArray that sorts arr. For instance, for an input array of size 10 and k = 2, an element belonging to index 6 in the sorted array will be located at either index 4, 5, 6, 7 or 8 in the input array.

Analyze the time and space complexities of your solution.

Example:

input:  arr = [1, 4, 5, 2, 3, 7, 8, 6, 10, 9], k = 2

output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] */


#include <iostream>
#include <vector>
#include <functional>
#include <queue>


using namespace std;

vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{
  // your code goes here
  // given an index i - sort all elements in the [i-k,i+k] range.
  // j = k+1, 2k+1, n-k-1
  // number of indexes (n-2k-2)(2k)log(2k)

    int size = arr.size();
    
    vector<int> result(size, 0);
      
    priority_queue<int, vector<int>, greater<int>> pq;   
    
    int count = 0;
      
    for (int i = 0; i < size; i++) 
    {
        pq.push(arr[i]);
        if(pq.size() == k+1)
        {
          result[count++] = pq.top();
          pq.pop();
        }
    }
  
    while(pq.size() != 0)
    {
        result[count++] = pq.top();
        pq.pop();
    }
  
    return result;
}
/*
i = 2; k = 2  

{1, 4, 5, 2, 3}, 7, 8, 6, 10, 9}
{1,2,3,{4,5,7,8,6},10,9}
{1,2,3,4,5,6,7,8},10,9}

i = 5, k = 2
sort start = 3, end = 7
*/

int main() {
  
  vector <int> arr = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
  
  vector<int> result;
  
  int k = 2;
  
  result = sortKMessedArray(arr, k);
  
  for (auto & i : result) {
      cout << i << " ";
  }
   cout << endl;
  return 0;
}
