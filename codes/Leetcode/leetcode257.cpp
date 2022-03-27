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
class Solution {
public:

    void dfs(TreeNode* root, int d, vector<TreeNode*>& path, vector<string>& ans) {
        if (root == NULL) {
            return;
        }
        if (path.size() <= d) {
            path.resize(d+1);
        }
        path[d] = root;

        if (root->left == NULL && root->right == NULL) {
            string s;
            for (int i = 0; i < d; ++i) {
                s += to_string(path[i]->val);
                s += "->";
            }
            s += to_string(root->val);
            ans.emplace_back(s);
            return;
        }

        if (root->left) {
            dfs(root->left, d+1, path, ans);
        }

        if (root->right) {
            dfs(root->right, d+1, path, ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<TreeNode*> path;

        dfs(root, 0, path, ans);
        return ans;
    }
};
