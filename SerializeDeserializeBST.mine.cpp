// Didn't have to do it in the form of a breath first search. 

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (root == NULL) return "[]";

        string result = "";

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            TreeNode * curr = q.front();
            q.pop();
            //cout << curr->val << " left: " << curr->left << "right: " << curr->right << endl;
            result += curr == nullptr ? "null," : to_string(curr->val) + ",";
            if (curr != nullptr) {
                curr->left == nullptr ? q.push((TreeNode*)nullptr) : q.push(curr->left);
                curr->right == nullptr ? q.push((TreeNode*)nullptr) : q.push(curr->right);
            }
        }
        int size = result.size();
        return "[" + result.substr(0,size-1) + "]";
    }

    void CreateTree(vector<string> & tokens, TreeNode * node, int id) {

        int size = tokens.size();

        if (2*id+1 > size-1) {
            node->left = NULL;
            node->right = NULL;
            return;
        }

        if (tokens[2*id+1] == "null") {
            node->left = NULL;
        } else {
            node->left = new TreeNode(stoi(tokens[2*id+1]));
            CreateTree(tokens, node->left, 2*id+1);
        }

        if (tokens[2*id+2] == "null") {
            node->right = NULL;
        } else {
            node->right = new TreeNode(stoi(tokens[2*id+2]));
            CreateTree(tokens, node->right, 2*id+2);
        }
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data == "[]") return NULL;

        string list = data.substr(1,data.size()-2);

        vector<string> tokens;

        int start = 0, end = 0;

        do {
            end = list.find(',', start);
            //cout << "s: " << start << " e: " << end << endl;
            if (end == string::npos) break;
            tokens.emplace_back(list.substr(start,end-start)); // Start position to the length of the end.
            start = end+1;
        } while (1);

        // cout << list << endl;

        TreeNode * root = new TreeNode(stoi(tokens[0]));

        CreateTree(tokens,root,0);

        return root;
    }
};
