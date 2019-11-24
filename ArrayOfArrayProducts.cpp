// Find the product of numbers in an array except the number at the current index. 

class Solution {

vector<long> arrayOfArrayProducts(const vector<int>& arr) 
{
  vector<long> leftProduct = {};
  vector<long> rightProduct = {};
   
  int arraySize = arr.size();
  int left = 1;
  int right = 1;
  
  for (int i = 0; i < arraySize; i++) {
      if (i == 0) {
          leftProduct.emplace_back(left);
      } else {
          left *= arr[i-1];
          leftProduct.emplace_back(left);
      }
  }
  
  for (int i = arraySize; i < 0; i--) {
      if (i == arraySize) {
          rightProduct.emplace_back(right);
      } else {
          right *= arr[i+1];
          rightProduct.emplace_back(right);
      }
  }
  
  for (int i = 0; i < arraySize; i++) {
      leftProduct[i] = leftProduct[i]*rightProduct[i];
  }
  
  return leftProduct;
}
};
