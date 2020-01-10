199. Binary Tree Right Side View
Medium

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // Would a level-order traversal work? 
        if (root == NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> result = {};
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0 ; i < size; i++) {
                 auto top = q.front();
                 q.pop();
                 if (top->left != NULL) q.push(top->left);
                 if (top->right != NULL) q.push(top->right);
                 
                 if (i == size-1) {
                     result.emplace_back(top->val);
                 }
            }
        }
        
        return result;
    }
};
