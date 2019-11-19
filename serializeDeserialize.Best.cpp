## deserialize and serialize a BST.

// [1,2,5,3,4,6,7] will be serialized as 1,2,4,#,#,5,#,#,3,#,#
// # will be used as the recursion exit
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if (root == NULL) return res;
        res += to_string(root->val);
        makeSerialize(root->left, res);
        makeSerialize(root->right, res);
        return res;
    }

    void makeSerialize(TreeNode* root, string& res) {
        if (root == NULL) {
            res += ",#"; return;
        }
        res += "," + to_string(root->val);
        makeSerialize(root->left, res);
        makeSerialize(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        int index = 0;
        return makeDeserialize(data, index);
    }

    TreeNode* makeDeserialize(string& data, int & index) {
        if (data[index] == '#') {
            index++;
            if (index < data.size()) index++;
            return NULL;
        }
        //get value of current tree
        int p = index;
        while (data[p] != ',') p++;
        int value = stoi( data.substr(index, p - index) );

        TreeNode * root = new TreeNode(value);
        index = p + 1;
        root->left = makeDeserialize(data, index);
        root->right = makeDeserialize(data, index);
        return root;
    }
};
