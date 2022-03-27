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

    bool containNode(TreeNode* root, TreeNode* v, vector<TreeNode*>& path) {
        if (root == NULL) {
            return false;
        }

        if (root->val == v->val
                || containNode(root->left, v, path)
                || containNode(root->right, v, path)) {
            path.push_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        containNode(root, p, path_p);
        containNode(root, q, path_q);
        int mvp = 0, mvq = 0;
        if (path_p.size() > path_q.size()) {
            mvp = path_p.size() - path_q.size();
        } else if (path_p.size() < path_q.size()) {
            mvq = path_q.size() - path_p.size();
        }

        while (mvp < path_p.size()) {
            if (path_p[mvp] == path_q[mvq]) {
                return path_p[mvp];
            }
            mvp++;
            mvq++;
        }
        return NULL;
    }
};
