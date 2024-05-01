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
    int findSecondMinimumValue(TreeNode* root) {
        std::vector<int> nodes;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == NULL) return;
            nodes.emplace_back(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        std::sort(nodes.begin(), nodes.end());
        std::vector<int> nums;
        nums.emplace_back(nodes[0]);
        for (int i = 1; i < nodes.size(); ++i) {
            if (nums[nums.size()-1] == nodes[i]) continue;
            nums.emplace_back(nodes[i]);
        }
        if (nums.size() == 1) nums.emplace_back(-1);
        return nums[1];
    }
};
