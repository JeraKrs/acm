/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialize_dfs(TreeNode* root, string& str) {
        if (!root) {
            return;
        }
        char buf[200];
        snprintf(buf, 200, "%d,%d,%d,", root->val, root->left ? 1 : 0, root->right ? 1 : 0);
        str += buf;
        serialize_dfs(root->left, str);
        serialize_dfs(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialize_str;
        serialize_dfs(root, serialize_str);
        return serialize_str;
    }

    TreeNode* deserialize_dfs(const string& data, int& p) {
        if (p >= data.size()) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode;

        int mv = p;
        while (mv < data.size() && data[mv] != ',') ++mv;
        root->val = atoi(data.substr(p, mv - p).c_str());
        root->left = root->right = NULL;

        p = mv + 5;
        if (data[mv+1] == '1') {
            root->left = deserialize_dfs(data, p);
        }

        if (data[mv+3] == '1') {
            root->right = deserialize_dfs(data, p);
        }
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p = 0;
        return deserialize_dfs(data, p);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
