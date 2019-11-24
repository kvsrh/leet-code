/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    
    queue<TreeNode *> q;
    
    q.push(root->left);
    q.push(root->right);
    
    while (!q.empty()) {
        
        TreeNode * t1 = q.front();
        q.pop();
        TreeNode * t2 = q.front();
        q.pop();
        
        if (t1 == NULL && t2 == NULL) continue;
        if (t1 == NULL || t2 == NULL) return false;
        
        if (t1->val != t2->val) return false;
        
        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
    }
    
    return true;
}   

};
