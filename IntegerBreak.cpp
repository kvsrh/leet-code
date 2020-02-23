Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

class Solution {
public:
    int integerBreak(int n) {
    
        // Dynamic programming. 
    
        vector<int> product (n+1,0);
        
        product[0] = 0;
        product[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int maxL = INT_MIN;
            if (i != n) {
                maxL = i;
            } else {
                maxL = 0;
            }
            
            for (int j = 1; j < i; j++) {
                maxL = max (maxL,  product[j]*product[i-j]);
            }
            
            product[i] = maxL;
        }
        return product[n];
    }
};
