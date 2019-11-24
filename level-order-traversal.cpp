/* Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
*/

/*
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Do a breath first search ...
        
        if (root == NULL) return {};
        
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size,0);
            for(int i = 0; i < size; i++) {
                TreeNode * curr = q.front();
                q.pop();
                if (curr->left != NULL) q.push(curr->left);
                if (curr->right != NULL) q.push(curr->right);
                level[i] = curr->val;
            }
            res.emplace_back(level);
        }
    return res;
    }
};
