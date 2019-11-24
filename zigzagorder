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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if (root == NULL) return vector<vector<int>>();
        
        vector<vector<int>> result;
        bool reverse = false;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode * curr = q.front();
                q.pop();
                int index = reverse ? size-1-i : i;
                level[index] = curr->val;
                if (curr->left != NULL) q.push(curr->left);
                if (curr->right != NULL) q.push(curr->right);
            }
            result.emplace_back(level);
            reverse ^= true;
        }
        
        return result;
    }
};
