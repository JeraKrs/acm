/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;

        int depth = 0;
        std::queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            depth++;

            while (n--) {
                Node* cur = que.front();
                que.pop();
                for (int i = 0; i < cur->children.size(); ++i) {
                    Node* next = cur->children[i];
                    if (next) {
                        que.push(next);
                    }
                }
            }
        }
        return depth;
    }
};
