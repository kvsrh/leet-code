863. All Nodes Distance K in Binary Tree
Medium

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void DistanceDown(TreeNode * target, vector<int> & result, int K) {
    if (target == NULL) return;
    if (K == 0) {
        result.emplace_back(target->val);
        return;
    }
    
    K--;
    DistanceDown(target->left, result, K);
    DistanceDown(target->right, result, K);
    
    return;
}

bool findTarget(TreeNode * root, TreeNode * target, vector<TreeNode*> & list) {
    if (root == NULL) return false;
    
    if (root == target) {
        list.emplace_back(target);
        return true;
    }
    
    if (findTarget(root->left, target, list)) {
        list.emplace_back(root);
        return true;
    }
    
    if (findTarget(root->right, target, list)) {
        list.emplace_back(root);
        return true;
    }
    return false;
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        // Given a node - find all the nodes which are at a K distance.
        
        vector<int> result; 
        
        vector<TreeNode * > rootToTarget; 
        
        // Check all lower distance nodes.
        
        DistanceDown(target, result, K);
        
        // Now check all nodes starting from the parent excluding the current sub-tree.
        
        findTarget(root, target, rootToTarget);
        
        int size = rootToTarget.size();

        for (int i = 1; i < size; i++) {
            if (K-i < 0) break;
            
            auto root = rootToTarget[i];
            if (K-i == 0) {
                cout << root->val << endl;
                result.emplace_back(root->val);
            }
            
            if (root->left == rootToTarget[i-1]) {
                DistanceDown(root->right, result, K-i-1);
                continue;
            }
            
            if (root->right == rootToTarget[i-1]) {
                DistanceDown(root->left, result, K-i-1);
                continue;
            }
        }
        
        return result;
    }
};
