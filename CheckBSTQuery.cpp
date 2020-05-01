Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree

Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree. 

We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.

 

Example 1:

Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
Output: true
Explanation: 
The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
Other valid sequences are: 
0 -> 1 -> 1 -> 0 
0 -> 0 -> 0

Example 2:

Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
Output: false 
Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.

Example 3:

Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
Output: false
Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.

 

Constraints:

    1 <= arr.length <= 5000
    0 <= arr[i] <= 9
    Each node's value is between [0 - 9].


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        
        TreeNode * current = root;
        
        if (current == NULL || arr.size() == 0)  return 0;
        
        if (current->val != arr[0]) return 0;
        
        for (int i = 1; i < arr.size(); i++) 
             
            if (current->left != NULL && current->left->val == arr[i]) {
                current = current->left;
                //cout << "Picking Left" << endl;
                continue;
            }
        
            if (current->right != NULL && current->right->val == arr[i]) {
                current = current->right;
                //cout << "Picking Right" << endl;
                continue;
            }
            
            return false;
        }
        
        if (current->left == NULL && current->right == NULL) {
            return true;
        }
        
        return false;
    }
};
*/

bool dfs (TreeNode * root, vector<int> & arr, int index) {
    
    if (root == NULL) {
        return 0; 
    }
    
    if (root->val != arr[index]) return false;
    
    if (index == arr.size()-1 && root->left == NULL && root->right == NULL) {
        return true;
    } 
    
    if (index == arr.size()-1) return false;
    
    bool foundLeft = dfs(root->left, arr, index+1);
    
    if (foundLeft) return true;
    
    bool foundRight = dfs(root->right, arr, index+1);
    
    if (foundRight) return true;
    
    return false;
}

class Solution {
    public: 
    
        bool isValidSequence(TreeNode * root, vector<int> & arr) {
            return dfs(root, arr, 0); 
        }
};

//             cout << "arr val - " << arr[i] << " index - " << i << " ";
            
//             int cVal = current->val;
//             int crVal = current->right != NULL ? current->right->val : -1;
//             int clVal = current->left != NULL ? current->left->val : -1;
            
//             cout << "current val : " << cVal << " current right : " << crVal <<
//                 " current left : " << clVal << endl;
