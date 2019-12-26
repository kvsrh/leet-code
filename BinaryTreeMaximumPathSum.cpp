###
124. Binary Tree Maximum Path Sum
Hard

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

###

int helper (TreeNode * root, int * maximum) {
        
        if (root == NULL) {
            return 0;
        }
        
        int max_left = 0, max_right = 0, max_local = 0;
        int result = 0;
        
        max_left = max(0, helper(root->left, maximum));
        max_right = max(0, helper(root->right, maximum));
        
        max_local = root->val + max_left + max_right;
        // max_local = max(max_local, root->val + max_left);
        // max_local = max(max_local, root->val + max_right);
        // max_local =  max(root->val, max_local);
        
        *maximum = max(*maximum,max_local);

        result = max(max_left, max_right) + root->val;
    
        return result;
    }

class Solution {
public:
    
    int maxPathSum(TreeNode * root) {
        
        int result = INT_MIN;
        helper(root, &result);
        return result;
    }
};

# Neat solution where in we check if we can get the max from the left and right. If we have a negative number from left and right,
we can ignore the number all together. 

/*

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        DFS(root, maxSum);
        return maxSum;
    }
    
    int DFS(TreeNode* root, int& maxSum){
        if(!root) return 0;
        int left = max(0, DFS(root->left, maxSum));
        int right = max(0, DFS(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
};

*/
