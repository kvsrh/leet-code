// Given a binary tree, determine if it is a valid binary search tree (BST).
// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
//  Both the left and right subtrees must also be binary search trees.

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
    bool isValidBST(TreeNode* root) {
    	return isValidBST_c(root, nullptr, nullptr);
    }
private:
	bool isValidBST_c(TreeNode* root, TreeNode* max, TreeNode* min) {
		if (root == nullptr)
			return true;
		if (max != nullptr && root->val >= max->val)
			return false;
		if (min != nullptr && root->val <= min->val)
			return false;

		return isValidBST_c(root->left, root, min) && isValidBST_c(root->right, max, root);
	}
}
