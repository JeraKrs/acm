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
class FindElements {
public:
    FindElements(TreeNode* root) {
        _root = root;
    }
    
    bool find(int target) {
        ++target;
        std::stack<int> command;
        while (target > 1) {
            if (target&1) command.push(1);
            else command.push(0);
            target >>= 1;
        }
        TreeNode* mov = _root;
        while (!command.empty()) {
            if (mov == nullptr) return false;
            int c = command.top();
            command.pop();
            if (c == 0) mov = mov->left;
            else mov = mov->right;
        }
        return mov;
    }
    TreeNode* _root;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
