// Given an array nums of n integers where n > 1,  return an array output such that output[i] is 
// equal to the product of all the elements of nums except nums[i].

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& arr) {
  
  int arraySize = arr.size();
   
  vector<int> leftProduct(arraySize,1);
  vector<int> rightProduct(arraySize, 1);
       
      
  int left = 1;
  int right = 1;
  
 for (int i = 0; i < arraySize; i++) {
      if (i == 0) {
          leftProduct[i] = left;
      } else {
          left *= arr[i-1];
          leftProduct[i] = left;
      }
 }
     for (int i = arraySize-1; i >= 0; i--) {
         if (i == arraySize-1) {
          rightProduct[i] = right;
        } else {
          right *= arr[i+1];
          rightProduct[i] = right;
        }
    }
      
  for (int i = 0; i < arraySize; i++) {
      leftProduct[i] = leftProduct[i]*rightProduct[i];
  }
  
  return leftProduct;
}    
};
