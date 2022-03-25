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
    bool exist(int bits, int height, TreeNode* root) {
        for (int i = height-1; i >= 0; --i) {
            if (bits & (1<<i)) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root != NULL;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int height = 0;
        TreeNode* mov = root;
        while (mov) {
            ++height;
            mov = mov->left;
        }

        int l = 0, r = 1<<(height-1);
        while (l + 1 < r) {
            int mid = (l+r)>>1;
            if (exist(mid, height-1, root)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return (1<<(height-1)) + l;
    }
};
