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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        _move = root;
        get_left();
    }

    void get_left() {
        while (_move && _move->left) {
            _stack.push(_move);
            _move = _move->left;
        }
    }
    
    int next() {
        int value = _move->val;
        if (_move->right) {
            _move = _move->right;
            get_left();
        } else if (!_stack.empty()) {
            _move = _stack.top();
            _stack.pop();
        } else {
            _move = NULL;
        }
        return value;
    }
    
    bool hasNext() {
        return _move;
    }
private:
    TreeNode* _move;
    std::stack<TreeNode*> _stack;

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
